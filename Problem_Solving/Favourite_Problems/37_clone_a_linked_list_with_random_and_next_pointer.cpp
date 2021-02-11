//problem link: https://leetcode.com/problems/copy-list-with-random-pointer/
// Reference linK:https://www.youtube.com/watch?v=VNf6VynfpdM&list=PLgUwDviBIf0r47RKH7fdWN54AbWFgGuii&index=14&ab_channel=takeUforward
// learning:
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
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
void push_forward(Node **head_ref, int new_data);
void print(Node *head);

/*
Algorithm: BETTER
create a copy of each node as deep copy and store it correspondingly for each original node in a set. 
in next iteration connect the deep copy pointers accordingly with refernce to original copy.
* Time: O(N), Space: O(N)
faster than 99%, space less than 44%
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> mp;
        Node *p = head;
        //Node *dumb=new Node(-1);
        // x->val=-1;
        // x->next=nullptr;
        // x->random=nullptr;
        while (p)
        {
            Node *dumb = new Node(p->val); // new to create new memory block, see constructor.
            mp[p] = dumb;
            p = p->next;
            dumb = dumb->next;
        } // map filled.// O(N)
        p = head;
        while (p)
        {
            mp[p]->next = mp[p->next];
            mp[p]->random = mp[p->random];
            p = p->next;
        }
        // cout<<mp[head->next]->next<<" ";
        // cout<<head->next->next;
        return mp[head];
    }
};
/*
Algorithm: OPTIMAL 
Create Nodes in between the original nodes and connect the pointers accordingly.
connect the random nodes using iter and front.
connect the random nodes nodes and also the 

* Time: O(N), Space: O(1)
*/
// 37_clone_a_linked_list_with_random_and_next_pointer.png
// 37_clone_a_linked_list_with_random_and_next_pointer3.png

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if(!head)
            return head;
        Node *original = head;
        Node *front = head->next;
        while (original)
        {
            Node *copy = new Node(original->val);
            copy->next = front;
            original->next = copy;
            original = front;
            if (front)
                front = front->next;
        }
        // inserted and copy is end, now random ka operation.
        original = head;
        while (original)
        {
            // what if random is pointing to null ?
            if (!original->random)
                original->next->random = nullptr;
            else
            original->next->random= original->random->next;
            original = original->next->next;
        }
        //  random set. Extract both the list seprately.
        Node *DeepCopy = head->next;
        Node *t = DeepCopy;
        original = head;

        while (original)
        {
            front = t->next;
            if (front)
            {
                t->next = front->next;
                t = front->next;
            }
            else
                t->next = nullptr;
            original->next = front;
            original = front;
        }
        return DeepCopy;
    }
};
int main()
{
    Node *head = nullptr;
    // Let us create linked list 1->2->3->4
    push_forward(&head, 5);
    push_forward(&head, 4);
    push_forward(&head, 3);
    push_forward(&head, 2);
    push_forward(&head, 1);
    Node *headTwo = nullptr;
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
void push_forward(Node **head_ref, int new_data)
{

    Node *workingNode = new Node(0);
    workingNode->val = new_data;
    workingNode->next = *head_ref;
    *head_ref = workingNode;
}
void print(Node *head) // return size coz required in one of the function
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
