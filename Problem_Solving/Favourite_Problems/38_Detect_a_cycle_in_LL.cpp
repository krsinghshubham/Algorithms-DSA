//problem link: https://leetcode.com/problems/linked-list-cycle/
// Reference linK: https://www.youtube.com/watch?v=354J83hX7RI&list=PLgUwDviBIf0r47RKH7fdWN54AbWFgGuii&index=8&t=6s&ab_channel=takeUforward
// learning:
// 36th is tougher variation of this.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);   
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void push_forward(ListNode **head_ref, int new_data);
void print(ListNode *head);
//O(n) space solution. 

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*>st;
        while(head)
        {
            if(st.find(head)!=st.end()) // cycle exist.
                return true;
            else
                st.insert(head);
            head=head->next;
        }
        return false;
    }
};
//O(1) space solution.
// slow , fast while slow==fast. this will always when ever there is a cycle. 
// and if no loop then fast will exhaust.
class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        if(!head || !head->next)
        return false;
        ListNode* slow=head;
        ListNode* fast=head;
  
        while(1) // and not equal to null ptr
        {   
            if(slow->next)
            slow=slow->next;
            else
                return false;
            if(fast->next && fast->next->next)
            fast=fast->next->next;
            else
                return false;
            if(slow==fast)
                break;
            
        }
        return true;
    }
};