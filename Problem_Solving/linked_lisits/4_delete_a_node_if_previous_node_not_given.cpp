//problem link:
// tutorial linK:
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FASTIO_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9
                       /*
Algorithm:
Since we do not have access to the node before the one we want to delete,
 we cannot modify the next pointer of that node in any way. 
 Instead, we have to replace the value of the node we want to delete with the value in the node after it,
  and then delete the node after it.
* Time: O(1), Space: O()
*/

 struct ListNode
 {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 
  void deleteNode(ListNode *node)
 {
    node->val=node->next->val;
    node->next=node->next->next;
    free(node->next);
 }
 int main()
 {
     FASTIO_TEMPLATE;
     int tc;
     cin >> tc;
     while (tc--)
     {
     }
     return 0;
 }