//problem link: https://leetcode.com/problems/merge-two-sorted-lists/
// tutorial linK: https://www.youtube.com/watch?v=EvgZCUhTosc&t=755s
// learning: how to use dummy/fake linked list which makes things easier
// *learnign: diff between (->) and (.) operators. 
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
similar to merge sort merge fuction
rest details in notebook
* Time: O(m+n), Space: O(1) coz only creating fake and last nodes

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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode dummy(-1); // dummy , consider its start of list
    ListNode *last = &dummy; //
    /*
    declaring as follows would have gave wrong ans since we are just storing address,not value.
    ListNode *dummy; 
    ListNode *last = dummy;
    study next line of return to get a new concept
    */
    while (l1 and l2) // jab tak dono hai
    {
        if (l1->val < l2->val)
        {    //imp 3 step process
            last->next = l1;
            last=last->next; // updating last
            l1 = l1->next;
        }
        else
        {
            last->next = l2;
            last=l2;
            l2 = l2->next;
        }
    }
    if (l1) // l1 bach gaya
    {
            last->next = l1;
    }
    if (l2) //l2 bach gaya;
    {
            last->next = l2;
    }
    return dummy.next; //we have to return its next 
    // * imp: for above return statement:
    /*
    In general, if you want to access a member of a struct or class, use object.member.
     If you have a pointer to a struct or class, use (*pointer).member, or the shorter pointer->member
    */
}
int main()
{
    ListNode *head = nullptr;
    // Let us create linked list 2,5,7,8
    push_forward(&head, 8);
    push_forward(&head, 7);
    push_forward(&head, 5);
    push_forward(&head, 2);
    //
    ListNode *headTwo = nullptr;
    // Let us create linked list 3,4,5,9,12
    push_forward(&headTwo, 8);
    push_forward(&headTwo, 7);
    push_forward(&headTwo, 5);
    push_forward(&headTwo, 2);
    print(head);
    cout << endl;
    print(headTwo);
    cout << endl;
    ListNode *createdNode = mergeTwoLists(head, headTwo);
    print(createdNode);

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