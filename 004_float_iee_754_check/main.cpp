#include <iostream>
#include <iomanip>
#include <limits>

int main()
{
    std::cout << std::boolalpha; // print bool as true or false rather than 1 or 0
    std::cout << "float: " << std::numeric_limits<float>::is_iec559 << '\n';
    std::cout << "double: " << std::numeric_limits<double>::is_iec559 << '\n';
    std::cout << "long double: " << std::numeric_limits<long double>::is_iec559 << '\n';
    bool b{};
    std::cout << "enter true/false: " << '\n';
    std::cin >> b; // "true" or "false", instead of 1 or 0, because of boolalpha
    std::cout << std::noboolalpha; // tuirn off bool print
    std::cout << std::setprecision(20);
    std::cout << 3.3333333333f << '\n'; // float
    std::cout << 3.3333333333  << '\n'; // double
}
