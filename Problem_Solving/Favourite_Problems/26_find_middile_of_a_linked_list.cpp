//problem link:  https://leetcode.com/problems/middle-of-the-linked-list/
// Reference linK: here only or somewhere dont remember, but its best
// learning: The Tortoise and the Hare (Floyd's Algorithm)
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
ListNode *middleNode(ListNode *head)
{
    // two pointer technique
    // two node one with 2x other with x,
    // when one will reach end, other will  be a middle
    ListNode *slow = head;
    // if(head==nullptr || head->next==nullptr)
    //     return head;

    while (head != nullptr && head->next != nullptr) // will handle case for 0 or 1 element
    {
        head = head->next->next;
        slow = slow->next;
        // cout<<head->val<<endl;
        // cout<<slow->val<<endl;
    }
    return slow;
}
int main()
{
    ListNode *head = nullptr;
    // Let us create linked list 1->2->3->4
    push_forward(&head, 5);
    push_forward(&head, 4);
    push_forward(&head, 3);
    push_forward(&head, 2);
    push_forward(&head, 1);
    print(middleNode(head));
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
// LINKED LIST TEMPLATE FINISHEDstruct ListNode

void push_forward(ListNode **head_ref, int new_data);
void print(ListNode *head);