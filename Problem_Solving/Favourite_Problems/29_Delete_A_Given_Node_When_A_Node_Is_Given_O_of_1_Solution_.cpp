//problem link: https://leetcode.com/problems/delete-node-in-a-linked-list/submissions/
// tutorial linK: In code
// learning:
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
Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
* Time: O(1), Space: O()
*/


class Solution
{
public:
  void deleteNode(ListNode *node)
  {
    node->val = node->next->val;
    node->next = node->next->next;
    // free(node->next);
  }
};

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};