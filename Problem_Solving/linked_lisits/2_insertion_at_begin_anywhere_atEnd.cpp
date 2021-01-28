//* re implementation by me.
// all insertion methods on Linked List
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
	int value;
	Node *next;
};
// ! keep note the argument for head. ** vs *
/* Given a reference (pointer to pointer) 
to the head of a list and an int, inserts 
a new node on the front of the list. */
void push_front(Node **head_ref, int new_value)
{
	/* 1. allocate node */
	
	Node *workNode = new Node();
	/* 2. put in the value */
	workNode->value = new_value;
	/* 3. Make next of new node as head */
	workNode->next = (*head_ref);
	/* 4. move the head to point to the new node */

	(*head_ref) = workNode;
	//* Time complexity O(1) as it does this in constant time
}

/* Given a node prev_node, insert a new node after the given 
prev_node */
void insertAfter(Node *prev_node, int new_value)
{
	/*1. check if the given prev_node is NULL */
	if (prev_node == NULL) // its the last node
	{
		cout << "the given previous node cannot be NULL";
		return;
	}

	/* 2. allocate new node */
	Node *workNode = new Node();
	/* 3. put in the value */
	workNode->value = new_value;
	/* 4. Make next of new node as next of prev_node */
	workNode->next = prev_node->next;
	/* 5. move the next of prev_node as new_node */
	prev_node->next = workNode;
	//* Time complexity O(1) as it does this in constant time
}

/* Given a reference (pointer to pointer) to the head 
of a list and an int, appends a new node at the end */
void push_back(Node **head_ref, int new_value)
{
	/* 1. allocate node */
	Node* workNode = new Node();
	Node *last = *head_ref; /* used in step 5*/ // to safeguard the next value;

	/* 2. put in the value */
	workNode->value = new_value;

	/* 3. This new node is going to be 
	the last node, so make next of 
	it as NULL*/
	workNode->next = nullptr;
	/* 4. If the Linked List is empty, 
	then make the new node as head */
	if (*head_ref ==nullptr)
		{*head_ref = workNode;
		 return;
		}
	/* 5. Else traverse till the last node */
	while (last->next != nullptr)
		last = last->next;
	/* 6. Change the next of last node */
	last->next = workNode;
	return;
	//* Time complexity O(n) as we traversals all the way to get the last pointer.
	// if we were to maintain a seprate pointer to store the address of last pointer too it would have took O(1) only.
}
void printList(Node *node)
{
	while (node != nullptr)
	{
		cout << node->value << " ";
		node = node->next;
	}
}

int main()
{
	/* Start with the empty list */
	Node *head = nullptr;
	// Insert 6. So linked list becomes 6->NULL
	push_back(&head, 6);
	// Insert 7 at the beginning.
	// So linked list becomes 7->6->NULL
	push_front(&head, 7);
	// Insert 1 at the beginning.
	// So linked list becomes 1->7->6->NULL
	push_front(&head, 1);
	// Insert 4 at the end. So
	// linked list becomes 1->7->6->4->NULL
	push_back(&head, 4);
	// Insert 8, after 7. So linked
	// list becomes 1->7->8->6->4->NULL
	insertAfter(head->next, 8);
	cout << "Created Linked list is: ";
	printList(head);
	return 0;
}
