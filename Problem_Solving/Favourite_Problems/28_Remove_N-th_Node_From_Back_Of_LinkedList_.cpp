//problem link:  https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// tutorial linK: LEETCODE EDITORIAL
// learning: TWO POINTER TECHNIQUE
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
/*
Algorithm:
Two pass: On the first pass, we find the list length LL.
 *Then we set a pointer to the DUMMY node and start to move it through the list till it comes to the (L - n)(L−n) th node. 
We relink next pointer of the (L - n)(L−n) th node to the (L - n + 2)(L−n+2) th node and we are done.
 * Time: O(2L-n)... first l to find length, then l-n to get nthe node.
* overall equiv O(L), Space: O(1)
*/
ListNode *removeNthFromEnd(ListNode *head, int n)
{ //! VERY IMPORTANT TO LEARN TECHNQUIE TO CREATE DUMMY POINTERS.
    // two pass
    ListNode *fake = new ListNode(-1); // ! very important step
    fake->next = head;
    //
    ListNode *current = head;
    //
    int length = 0;
    while (current)
    {
        length++;
        current = current->next;
    }
    // head nulled
    //cout << length;
    //
    length = length - n;
    current = fake; // fake list... of which 1st is dummy so it will handle cases with 1 and two elements too.

    while (length--)
        current = current->next;
    //
    current->next = current->next->next;
    return fake->next;
}

//ONE PASS ALGORITHM. tWO POINTER TECHNIQUE.
  ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
       
    //* in one pass, time O(n), space O(1)
    /*
    TAKE TWO POINTERS
    advance one by one step, other by n steps. when fast will be at end, slow will be at length-nth node.
    */
   ListNode * dummy= new ListNode(-1);
   dummy->next=head;
   ListNode * lead=dummy,* trail=dummy; // dummy to avoid cases of 1 nd 2 elems
   //n-=1;
        while(n--)
    {
        lead=lead->next;
    }
        cout<<endl<<lead->val<<endl;
                cout<<endl<<trail->val<<endl;

    // now we will move both lead and trail and as soon lead reach null trail be at the nth place form last
    while(lead->next) // coz we need to keep trail one node back to make it jump to next of requirement
    {
        lead=lead->next;
        trail=trail->next;
    }
        cout<<endl<<trail->val<<endl;

    // trail is at nth place from last
    trail->next=trail->next->next;
    // removed
    return dummy->next; // 1st crreates dummy elem.
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
    int n = 2;
    removeNthFromEnd(head, n);
    cout << endl;
    print(head);
    cout << endl;

    return 0;
}