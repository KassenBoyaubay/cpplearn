#include <iostream>
#include <vector>
#include <string>

using namespace std;

void foo(int)
{
}

int add(int, int);

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    cout << '\n';
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << '\n';

    cout << "add from add.cpp 2+3=" << add(2, 3) << '\n';

    // attribute for compiler
    // don't give warning if var is unused
    // volatile = don't remove var in optimization process
    [[maybe_unused]] unsigned int x { 5 }; // direct-list-initialization
    // foo(x); // should give warning and warning is treated as error

    int t {}; // value-initialization
    cout << "enter 1 value: " << '\n';
    cin >> t; 
    cout << "you entered " << t;
    
    cout << endl;
}
