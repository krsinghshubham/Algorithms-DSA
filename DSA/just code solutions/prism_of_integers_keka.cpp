// Find the next lexicographically
// greater permutation of a word

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int i = 0,r;
	for (i; i < n; i++)
	{
		int k = i;
		while (k--)
			cout << " ";
		for (int j = i + 1; j <= n; j++)
		{
			// while(k--)
			// cout<<" ";
			cout << j << " ";
		}
		cout << "\n";
		r=i;
	}
	i=r;
	if (i == n - 1)
	{
		for (i=i-1; i >= 0; i--)
		{
			int k = i;
			while (k--)
				cout << " ";
			for (int m = i + 1; m <= n; m++)
				cout << m << " ";
			cout << endl;
		}
	}
	return 0;
}