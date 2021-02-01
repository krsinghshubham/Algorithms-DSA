
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9

void solve()
{
	int n, dd;
	cin >> n >> dd;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	// so the observation is if we can get 0 at unit place then we can subtact that no and 10+no, there... which will be relative no.
	// if 71.........79 ,80, 70, so nos above >d*10+10 will work.
	// given d in 1 to 9;

	for (auto x : arr)
	{
		int d = dd;
		//cout<<"curr no: "<<x<<endl;
		int nox = 10 * d; //79
		if (x > nox)
		{
			cout << "yes" << endl;
			continue;
		}

		//24,25,27
		bool flag = false;
		while (x>0)
		{ // 25 , 7 14 21 28 35 42 49
			if (x % 10 == d)
			{
				flag = true;
				break;
			}
			x -= d;
		}
		if (flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}

int main()
{
	int tc = 1;
	cin >> tc;
	while (tc--)
	{
		solve();
	}

	return 0;
}
