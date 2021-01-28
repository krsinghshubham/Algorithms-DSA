//problem link:https://leetcode.com/problems/palindrome-linked-list/
// tutorial linK:
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
bool isPalindrome(ListNode *head);

/*
Algorithm:
/*
1-  >  2-> 3-> 2->1
           m
1-> 6->  2-> 2-> 6-> 1
         m
find mid.... 
pass next of mid to reverse and store next of mid.
while(next of mid!=null)
compare, failed return true;
* Time: O(N), Space: O(1)
*/

ListNode *reverse(ListNode *head)
{
    // 1-  >  2-> 3-> 2->1
    ListNode *prev = nullptr;
    ListNode *curr = head, *nextNode;
    // some loop
    while (curr != nullptr)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

bool isPalindrome(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) // even and odd both
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    //  slow= mid; // ! this commented code will give wrong output for,  Input: [1,1,2,1] Output:true Expected: false
    //  if(slow->next==nullptr && slow->val!=head->val)
    //      return false;
    // cout<<slow->val;
    ListNode *rvNew = reverse(slow); // reversing from mid-next
    while (rvNew != nullptr)
    {
        if (rvNew->val != head->val
            return false;
        head = head->next;
        // cout<<rvNew->val<<" ";
        rvNew = rvNew->next;
    }

    return true;
}

int main()
{
    ListNode *head = nullptr;
    ListNode *headTwo = nullptr;
    push_forward(&head, 2);
    push_forward(&head, 1);
    // Let us create linked list 2,5,7,8
    push_forward(&headTwo, 1);
    push_forward(&headTwo, 2);
    push_forward(&headTwo, 2);
    push_forward(&headTwo, 1);
    print(head);
    cout << endl;
    print(headTwo);
    cout << endl;
    bool xk = isPalindrome(head);
    if (xk)
        cout << "true and correct is false";
    else
    {
        cout << "false and correct is also false";
    }
    cout << endl;

    bool x = isPalindrome(headTwo);
    if (x)
        cout << "true and correct is also true";
    else
    {
        cout << "false and correct is true";
    }
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