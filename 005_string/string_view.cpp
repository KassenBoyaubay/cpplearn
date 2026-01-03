#include <iostream>
#include <string>
#include <string_view>

void printString(std::string str) // str make a copy of its initializer
{
  std::cout << str << '\n';
}

// str provides read-only access to whatever argument is passed in
void printSV(std::string_view str) // now a std::string_view
{
  std::cout << str << '\n';
}

int main() {
  {
    // When s is initialized, the C-style string literal
    // "Hello, world!" is copied into memory allocated for std::string s
    std::string s{"Hello, World\n"};
    // This example makes two copies of the C-style string “Hello, world!”:
    // one when we initialize s in main(), and another when we initialize
    // parameter str in printString()
    printString(s);
  }
  {
    // string view can be initialized with:
    // C-style literal (here), std::string, and std::string_view
    // if object is changed of what view "views" then it becomes invalid,
    // because it object maybe moved/truncated/elongated and view doesn't know
    std::string_view s{"Hello, world!"}; // now a std::string_view
    // When we initialize std::string_view s with C-style string literal "Hello,
    // world!", s provides read-only access to “Hello, world!” without making a
    // copy of the string. When we pass s to printSV(), parameter str is
    // initialized from s. This allows us to access “Hello, world!” through str,
    // again without making a copy of the string.
    printSV(s);
  }
  {
    using namespace std::string_literals;      // access the s suffix
    using namespace std::string_view_literals; // access the sv suffix

    std::cout << "foo\n";   // no suffix is a C-style string literal
    std::cout << "goo\n"s;  // s suffix is a std::string literal
    std::cout << "moo\n"sv; // sv suffix is a std::string_view literal
  }
  {
    // This makes constexpr std::string_view the preferred choice when string
    // symbolic constants are needed.
    constexpr std::string_view s{
        "Hello, world!"}; // s is a string symbolic constant
    std::cout
        << s << '\n'; // s will be replaced with "Hello, world!" at compile-time
  }
  return 0;
}
