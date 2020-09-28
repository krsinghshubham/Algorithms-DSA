#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    int i=0, x=0;
    for (const string& word : msg)
    {
        cout << word << " "<<++i<<" check "<<x++;
    }
    cout << endl;
    int xg;
    cin>>xg;
    cout<<xg+9<<endl;

 }
