//problem link: https://leetcode.com/problems/rotate-list/
// tutorial linK: commented
// learning:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i, n) for (int i = 0; i < n; i++)
#define FASTIO_TEMPLATE ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
brute force , giving TLE
* Time: O(), Space: O()
*/
class Solution
{
public:
    void rotate(ListNode *&head) //* passing by refrence , VERY IMPORTANT
    {
        ListNode *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next->next = head;
        head = temp->next; // updating head.
        temp->next = nullptr;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head;

        while (k--)
        {
            rotate(head);
        }
        return head;
    }
};
// * brute force finished
/*
Algorithm:
brute force , giving TLE
* Time: O(n), Space: O(1)
*/
/*
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(!head || !head->next) // if no or single element then return the list
            return head;
        ListNode* forLen=head; // to count the length
        int count=0;
        while(forLen)
        {
            count++;
            forLen=forLen->next;
        }
        // the idea is to get the node which will be length-k, make its next to null and 
        // bacha list ke next to suru me dalna
        forLen=head; // not assigning to save memory space
        k=k%count;   // to handle cycles
        if(k==0)   // no rotation required wii be at same positoon.
            return head; 
        count-=k+1; // 1 to be at one place back
        while(count--)
        {
            forLen=forLen->next; // position reaached 
        } // forLen is at third...
        ListNode* result=forLen->next; // store for result otherwise it will change
        ListNode* newHead=forLen->next; // bache list ka head
        while(newHead->next)
            newHead=newHead->next;//tail ho gya,tail me head ko point kro and                                           forlen(jaha se link tuti thi) ke next me null;
        newHead->next=head; // link it to beginnign
        forLen->next=nullptr; // jaha se tutta tha uske next me nullptr.
     
        
        return result;
    }
};
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