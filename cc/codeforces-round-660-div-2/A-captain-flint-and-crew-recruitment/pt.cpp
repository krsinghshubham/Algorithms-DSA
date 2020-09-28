#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
int n;
int limit=10000;
cin>>n;
string s="7";

    int count=0;

while(limit--){
    if(stoll(s)%n==0)
    {
        cout<<++count;
        break;
    }
    else
    {s.append("7");
        ++count;
    }
    
}

}



