// done already concept same one in array section.
//problem link: https://leetcode.com/problems/linked-list-cycle-ii/
// tutorial linK: // https://www.youtube.com/watch?v=QfbOhn0WZ88&list=PLgUwDviBIf0r47RKH7fdWN54AbWFgGuii&index=11&t=842s&ab_channel=takeUforward
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

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    if (!head || !head->next)
        return nullptr;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
        if (!fast || !fast->next) // in case there is no loop at all.
            return nullptr;
    } while (slow != fast);
    // slow == fast now. now move one pointer to start and do again, 2nd meet is ans.
    fast = head;
    if (slow == head) // ! IMPORTANT NOTE.
        return slow; // case when 0th node is the ans.because it will same condition again and again
    do
    {
        slow = slow->next;
        fast = fast->next;
    } while (slow != fast);
    return slow; // either.
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
    ListNode *headTwo = nullptr;
    // Let us create linked list 2,5,7,8
    push_forward(&headTwo, 8);
    push_forward(&headTwo, 7);
    push_forward(&headTwo, 5);
    push_forward(&headTwo, 2);
    print(head);
    cout << endl;
    print(headTwo);
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