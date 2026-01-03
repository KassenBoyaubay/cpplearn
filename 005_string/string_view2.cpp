#include <iostream>
#include <string>
#include <string_view>

std::string getName() {
  std::string s{"Alex"};
  return s;
}

int main() {
  {
    // The getName() function is returning a std::string containing the string
    // “Alex”. Return values are temporary objects that are destroyed at the end
    // of the full expression containing the function call. We must either use
    // this return value immediately, or copy it to use later. But
    // std::string_view doesn’t make copies. Instead, it creates a view to the
    // temporary return value, which is then destroyed. That leaves our
    // std::string_view dangling (viewing an invalid object), and printing the
    // view results in undefined behavior.
    std::string_view name{
        getName()};            // name initialized with return value of function
    std::cout << name << '\n'; // undefined behavior
  }
  {
    // A std::string literal (created via the s literal suffix) creates a
    // temporary std::string object. So in this case, "Alex"s creates a
    // temporary std::string, which we then use as the initializer for name. At
    // this point, name is viewing the temporary std::string. Then the temporary
    // std::string is destroyed, leaving name dangling. We get undefined
    // behavior when we then use name.  using namespace std::string_literals;
    std::string_view name{"Alex"s}; // "Alex"s creates a temporary std::string
    std::cout << name << '\n';      // undefined behavior
    // It is okay to initialize a std::string_view with a C-style string literal
    // or a std::string_view literal. It’s also okay to initialize a
    // std::string_view with a C-style string object, a std::string object, or a
    // std::string_view object, as long as that string object outlives the view.
  }
  {
    std::string s{"Hello, world!"};
    std::string_view sv{s}; // sv is now viewing s

    s = "Hello, universe!";  // modifies s, which invalidates sv (s is still
                             // valid)
    std::cout << sv << '\n'; // undefined behavior

    sv = s;                  // revalidate sv: sv is now viewing s again
    std::cout << sv << '\n'; // prints "Hello, universe!"
  }
  {
    // Do not return std::string_view if object is destroyed at the end of
    // function (local object) or If the argument is a temporary object (that
    // will be destroyed at the end of the full expression containing the
    // function call), the std::string_view return value must be used in the
    // same expression. After that point, the temporary is destroyed and the
    // std::string_view is left dangling. So "If an argument is a temporary that
    // is destroyed at the end of the full expression containing the function
    // call, the returned std::string_view must be used immediately, as it will
    // be left dangling after the temporary is destroyed."
    auto lam = []() -> std::string_view {
      return "C-style literal that lives forever";
    };
    std::cout << lam() << "\n"; // ok, because C-style string literals exist for
                                // the entire program
  }
  {
    // modifying view (not object itself)
    std::string_view str{"Peach"};
    std::cout << str << '\n';

    // Remove 1 character from the left side of the view
    str.remove_prefix(1);
    std::cout << str << '\n';

    // Remove 2 characters from the right side of the view
    str.remove_suffix(2);
    std::cout << str << '\n';

    str = "Peach"; // reset the view
    std::cout << str << '\n';
  }
  {
    // The ability to view just a substring of a larger string comes with one
    // consequence of note: a std::string_view may or may not be null-terminated
    // Consider the string “snowball”, which is null-terminated (because it is a
    // C-style string literal, which are always null-terminated). If a
    // std::string_view views the whole string, then it is viewing a
    // null-terminated string. However, if std::string_view is only viewing the
    // substring “now”, then that substring is not null-terminated (the next
    // character is a ‘b’).

    // A C-style string literal and a std::string are always null-terminated.
    // A std::string_view may or may not be null-terminated.

    // If you have a non-null-terminated std::string_view and you need a
    // null-terminated string for some reason, convert the std::string_view into
    // a std::string
  }
  {
    // Summary:
    // https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2/#stringvsstringview

    // Insights

    // Things to remember about std::string:

    // Initializing and copying std::string is expensive, so avoid this as much
    // as possible.
    //
    // Avoid passing std::string by value, as this makes a copy.
    //
    // If possible, avoid creating short-lived std::string objects.
    //
    // Modifying a std::string will invalidate any views to that string.
    //
    // It is okay to return a local std::string by value.
    //
    // Things to remember about std::string_view:
    //
    // std::string_view is typically used for passing string function parameters
    // and returning string literals.
    //
    // Because C-style string literals exist for the entire program, it is
    // always okay to set a std::string_view to a C-style string literal.
    //
    // When a string is destroyed, all views to that string are invalidated.
    //
    // Using an invalidated view (other than using assignment to revalidate the
    // view) will cause undefined behavior.
    //
    // A std::string_view may or may not be null-terminated.
    //
  }
  return 0;
}
