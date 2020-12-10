// CPP program to find MSB
// number for given n.
#include <bits/stdc++.h>
using namespace std;

int setBitNumber(int n)
{

	int k = (int)(log2(n));  // +1 for positon from right

	return k;
}

int main()
{
	int n = 4;
	cout << setBitNumber(n);
	return 0;
}
// for right most bit: int k= (int)(log2(n & n-1)); // + 1 for correct postionk;