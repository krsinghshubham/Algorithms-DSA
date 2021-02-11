//problem link:  https://leetcode.com/problems/add-two-numbers/
// Reference linK:
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
simple carry and sum, implemented smartly... not efficient

* Time: O(max(m,n)), Space: O(max(m,n)+1)
*/
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *fake = new ListNode(0);
    ListNode *temp = fake;
    int carry = 0;
    while (l1 || l2)
    {
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        int sum = x + y + carry;
        cout << sum << endl;
        fake->next = new ListNode(sum % 10);
        fake = fake->next; //!fake is now poiting to the update pointer
        carry = sum / 10;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    if (carry > 0) //! leftover carry
        fake->next = new ListNode(carry);
    return temp->next;
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