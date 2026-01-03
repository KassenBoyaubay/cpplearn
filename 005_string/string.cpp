#include <iostream>
#include <string>

int main() {
  using namespace std::string_literals;

  // C-style string literals are const objects that are created at the start of
  // the program and are guaranteed to exist for the entirety of the program.
  // Unlike C-style string literals, std::string and std::string_view literals
  // create temporary objects. These temporary objects must be used immediately,
  // as they are destroyed at the end of the full expression in which they are
  // created.

  // resolves to
  // std::string { "Hello", 5},
  // which creates a temporary std::string initialized with C-style string
  // literal “Hello” (which has a length of 5, excluding the implicit
  // null-terminator).
  std::cout << "Hello"s << '\n';

  // when using operator>> to extract a string from std::cin, operator>> only
  // returns characters up to the first whitespace it encounters. Any other
  // characters are left inside std::cin, waiting for the next extraction. so it
  // will only extract first name std::ws input manipulator tells std::getline()
  // to ignore any leading whitespace characters that may be left by previous
  // std::cin, that's why we use std::ws
  std::cout << "Enter your full name: ";
  std::string name{};
  std::getline(std::cin >> std::ws, name); // read a full line of text into name

  std::cout << "Enter your age: ";
  int age{}; // age needs to be an integer, not a string, so we can do math with
             // it
  std::cin >> age;

  // age is signed, and name.length() is unsigned -- we shouldn't mix these
  // We'll convert name.length() to a signed value
  int nameLen{static_cast<int>(
      name.length())}; // get number of chars in name (including spaces)

  std::cout << "Your age + length of name is: " << age + nameLen << '\n';

  return 0;
}
