//problem link: https://leetcode.com/problems/intersection-of-two-linked-lists/solution/
// tutorial linK:https://www.youtube.com/watch?v=gE0GopCq378&ab_channel=mycodeschool
// learning: tutorial is leetcode editorial
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
Approach 1: Brute Force
For each node ai in list A, traverse the entire list B and check if any node in list B coincides with ai.
 *Time complexity : O(mn)O(mn).
*Space complexity : O(1)O(1).
*/
//code:
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *pa = headA, *pb;
    while (pa != nullptr)
    {
        for (pb = headB; pb != nullptr; pb = pb->next)
        {
            if (pa == pb)
            {
                return pa;
            }
        }
        pa = pa->next;
    }
    return nullptr;
}

//!___________________
/*
Algorithm:
Approach 2: Hash Table
Traverse list A and store the address / reference to each node in a hash set. Then check every node bi in list B: if bi appears in the hash set, then bi is the intersection node.
*Time complexity : O(m+n)O(m+n).
*Space complexity : O(m)O(m) or O(n)O(n).
* Time: O(), Space: O()
*/
//code:
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    set<ListNode *> st; // imp: we are definning ListNode* and not ListNode
    ListNode *pa = headA;
    // adding to set
    while (headA)
    {
        st.insert(headA);
        headA = headA->next;
    }
    while (headB)
    {
        if (st.find(headB) != st.end())
            return headB;
        headB = headB->next;
    }
    return nullptr;
}
//!____________________
/*
Algorithm:
use case: metro map... find the intesecting map... we just have to find already meger list, not merge them
ok... so 
get both length... find difference... 
skip that much in big one...
now both will be at same distance from merging point...
move togeher untill same...
return
Another approcah might be two pointer technique... when one list exhauset move it to the first of 2nd list, and when 2nd list exhaust move it to the first one ... this way they will traverse all nodes
* OPTMISED SOLUTION
* Time: O(m+n), Space: O(1)

*/
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{

    if (headA == nullptr || headB == nullptr)
        return nullptr;
    int lenA = 0, lenB = 0;
    ListNode *A = headA;
    ListNode *B = headB;
    while (A != nullptr)
    {
        lenA++;
        A = A->next;
    }

    while (B != nullptr)
    {
        lenB++;
        B = B->next;
    }
    int diff;

    // cout<<headA<<"\n"<<headB<<"\n";
    if (lenA > lenB)
        diff = lenA - lenB;
    if (lenB > lenA) // swap the two lists so that we need not to use two if conditions for both kind of diff.
    {
        ListNode *temp = headA;
        headA = headB;
        headB = temp;
        diff = lenB - lenA;
    }

    // cout<<diff;
    while (diff--) // diff might be zero
        headA = headA->next;
    // cout<<headA->val;
    if (headA == headB)
        return headA;
    while (headA != headB)
    {
        //         cout << "before moving\n";
        //
        //         cout << headA << "\n";
        //         cout << headB << "\n";
        //
        headA = headA->next;
        headB = headB->next;
        //         cout << "after moving\n";

        // cout << headA << "\n";
        // cout << headB << "\n";
        if (headA == headB)   // ! we need to check after swapping 
            return headA; // also if value same and address not then thats not the merging point.
    } 

    return nullptr;
}

// main fuction not complete
int main()
{
    ListNode *head = nullptr;
    // Let us create linked list 1->2->3->4
    push_forward(&head, 5);
    push_forward(&head, 4);
    push_forward(&head, 3);
    push_forward(&head, 2);
    push_forward(&head, 1);
    print(head);
    return 0;
}