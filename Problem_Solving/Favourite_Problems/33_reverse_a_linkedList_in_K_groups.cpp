//problem link: https://leetcode.com/problems/reverse-nodes-in-k-group/
// tutorial linK: https://www.youtube.com/watch?v=Of0HPkk3JgI&list=PLgUwDviBIf0r47RKH7fdWN54AbWFgGuii&index=10&ab_channel=takeUforward
// learning:
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
/*
Algorithm:
Optimal: 
keep track of all the 4 pointers, for revision or confusion refer tut.
for a group of K , k-1 nodes will get traverse. will do till count > k.
handle k group at a time. 
1. *dummy always at head. so that it can be returned next. 
2. *pre first node of each group. 
3. *curry next of pre, and *nexy next of *curry.
* Time: O(N), Space: O(1)
*/

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (!head || k == 1)
        return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *pre = dummy, *curry = dummy, *nexy = dummy;
    int count = 0;
    while (curry->next) // coz 1st is not dummy->next;
    {
        count++;
        curry = curry->next;
    } // length of Linked List calculated.
    // algorithm starts here
    while (count >= k)
    {
        curry = pre->next;
        nexy = curry->next;
        // 33_reverse_a_linkedList_in_K_groups.png
        for (int i = 1; i < k; i++) // k-1 operation will take place.
        {
            curry->next = nexy->next; // note we are changing the pointer of curry and not the node . because curry will be always 1st node of the group.
            nexy->next = pre->next;   // link reversed, and points to pre->next and not curry coz curry will always be 1st node, and pre and nexy will get updated.
            pre->next = nexy;
            nexy = curry->next;
        }
        count -= k;
        pre = curry; // some changes will be done again at line 47,48, and pre=curry coz curry only carried the 1st node of the group.
    }
    return dummy->next;
    
}

int main()
{
    ListNode *head = nullptr;
    // Let us create linked list 1->2->3->4_5
    push_forward(&head, 7);
    push_forward(&head, 6);
    push_forward(&head, 5);
    push_forward(&head, 4);
    push_forward(&head, 3);
    push_forward(&head, 2);
    push_forward(&head, 1);
    print(head);
    cout << endl;
    ListNode *Newhead = reverseKGroup(head, 3);
    print(Newhead);
    cout << endl;
    return 0;
}
void push_forward(ListNode **head_ref, int new_data)
{

    ListNode *workingNode = new ListNode();
    workingNode->val = new_data;
    workingNode->next = *head_ref;
    *head_ref = workingNode;
}
void print(ListNode *head) // return size coz required in one of the function
{
    int size = 0;
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
        size++;
    }
    //return size;
}
// LINKED LIST TEMPLATE