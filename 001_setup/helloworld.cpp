#include <iostream>
#include <vector>
#include <string>

using namespace std;

void foo(int)
{
}

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    // unsigned int x { 5 };
    // foo(x); // should give warning and warning is treated as error
}
