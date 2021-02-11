//problem link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// Reference linK: Leetcode discuss : https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/discuss/150321/Easy-Understanding-Java-beat-95.7-with-Explanation
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
    Node *prev;
    Node *next;
    Node *child;
};

/*
Algorithm:
Start form the head , move one step each time to the next node
When meet with a node with child, say node p, follow its child chain to the end and connect the tail node with p.next, by doing this we merged the child chain back to the main thread
Return to p and proceed until find next node with child.
Repeat until reach null
keep the diag. handy
* Time: O(N), Space: O(1)
*/

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (!head)
            return head;

        Node *p = head;
        while (p)
        {
            if (!p->child)
                p = p->next;
            else
            {
                Node *temp = p->child;

                while (temp->next)
                    temp = temp->next;

                temp->next = p->next;
                if (p->next) // * IMPORTANT, CONSIDER TC: [1,null,2,null,3,null] THAT IS 3 NODES CONNECTED VERTICALLY WITH NEXT NULL FOR ALL
                    p->next->prev = temp;
                p->child->prev = p;

                p->next = p->child;
                p->child = nullptr;
            }
        }
        return head;
    }
};