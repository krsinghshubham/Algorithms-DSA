
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
/*
Algorithm:

* Time: O(), Space: O()
*/
void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        int count = 1, ans = 0;
        int arr[n];
        fo(i, n)
                cin >>
            arr[i];
        for (int i = 1; i < n; i++)
        {
            while (arr[i] == arr[i - 1])
            {
                count++;
                i++;
            }

            ans = max(ans, count);
            if (count > 1)
                i--;
            count = 1;
        }
        cout << ans << endl;
    }
}
// 5
// 6
// 1 1 1 2 3 4
// 5
// 1 1 2 2 3
// 4
// 2 2 2 2
// 3
// 1 2 3
// 1
// 1
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