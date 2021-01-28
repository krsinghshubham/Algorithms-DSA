//problem link: https://leetcode.com/problems/reverse-linked-list/
// tutorial linK: ITERATIVE: https://www.youtube.com/watch?v=sYcOK51hl-A&t=551s&ab_channel=mycodeschool
// tutorial linK: RECURSIVE(my code school): https://www.youtube.com/watch?v=KYH83T4q6Vs&t=8s&ab_channel=RachitJain
// learning: 2 ways of linked reversal
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FAST_INPUT_OUTPUT_TEMPLATE_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define PI 3.1415926535897932384626
#define INF 1000000000 //10 ^9

class Node
{
public:
    int data;
    Node *next;
};
// Node *head = NULL;

// * normal printing iteratively
void printWithoutRecursion(Node *head) // return size coz required in one of the function
{
    int size = 0;
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
        size++;
    }
    //return size;
}
void push_forward(Node **head_ref, char new_data)
{

    Node *workingNode = new Node();
    workingNode->data = new_data;
    workingNode->next = *head_ref;
    *head_ref = workingNode;
}

/*
* ITERATIVE METHOD TO REVERSE
Algorithm: IN NOTES
*/
Node *IterativeReversal(Node *head)
{
    Node *current = head, *prev = nullptr, *nextNode;
    while (current != nullptr)
    {
        nextNode = current->next; //1.

        current->next = prev; // 2.
        prev = current;       // 3. previous updated to current for next iteration
        current = nextNode;   // 4. moved to next node
    }
    head = prev; //  ! node will point to current node // VERY IMPORTANT STEP, AND WE ARE MOVING PREV INTO HEAD AND NOT CURRENT, BECAUSE CURRENT WOULD CONATION NULL
                 // AS ITS THE LAST NODE, BUT PREV WILL CONTAIN THE ADDRESS OF THE LAST NODE.

    return head;
}
//* Time: O(N), Space: O(1)
// * DONE
/*


* RECURSIVE METHOD TO REVERSE
Algorithm: IN NOTES (where we need not to return pointer to head and declaration of head GLOBALLY was must) , also leetcode editorial is explained below
*/
// * Time: O(N), Space: O(1) // same as recursive
// * DONE
// ! HOW TO SOLVE IF HEAD IS NOT DECLARED GLOBALLY, use &
/*Approach #3 (Recursive) FROM LEETCODE EDITORIAL
The recursive version is slightly trickier and the key is to work backwards. Assume that the rest of the list had already been reversed, now how do I reverse the front part? Let's assume the list is: n1 → … → nk-1 → nk → nk+1 → … → nm → Ø
refer tutorial.
*/
Node *reverseList(Node *head)
{
    if (head == nullptr || head->next == nullptr) // two handle corner cases where ll have either one or two nodes only.
        return head;
    Node *p = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
}

int main()
{
    Node *head = nullptr;
    // ! declaraing head globally so that can be smoothly ran for recursive function
    // Let us create linked list 1->2->3->4
    push_forward(&head, 5);
    push_forward(&head, 4);
    push_forward(&head, 3);
    push_forward(&head, 2);
    push_forward(&head, 1);

    cout << "\nLinked list : \n";
    printWithoutRecursion(head);

    // cout << "\nReversed Linked list after revering iteratively: \n";
    // Node *newHead = IterativeReversal(head);
    // printWithoutRecursion(newHead);
    // * ONLY ONE CAN BE EXECUTED AT A TIME BECAUSE THE LINKER LISTS WILL CHANGE.
    cout << "\nReversed Linked list after revering recursively: \n";
    Node *newHeadSecond = reverseList(head);
    printWithoutRecursion(newHeadSecond);

    // cout << "\nReversed Linked list after revering recursively Leetcode logic: \n";
    // Node *newHeadSecond = reverseList(head);
    // printWithoutRecursion(newHeadSecond);
    return 0;
}