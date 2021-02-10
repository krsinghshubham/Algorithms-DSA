#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
};
// * normal printing iteratively
int printWithoutRecursion(Node *head) // return size coz required in one of the function
{
	int size=0;
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
		size++;
	}
	return size;
}
// *forward traversal using recursion
void printForwared(Node *head)
{
	if (head == nullptr)
		return;
	cout << head->data << " ";
	printForwared(head->next);
}
//! UNDERSATING OF BELOW CONCEPT IS VERY IMPORTANT.
//* function to print reverse of Linked list WITHOUT ACTUALLY REVERSING IT.
void printReverse(Node *head)
{
	if (head == nullptr)
		return;
	printReverse(head->next);
	cout << head->data << " ";
}
//*
/* Function to reverse the linked list */
/*
Stack based solution to print linked list reverse. Push all nodes one by one to a stack. 
Then one by one pop elements from stack and print. This also requires extra space.
*/

void backPrintWithoutRecursion(Node **head, int n)
{
	int j = 0;
	Node *current = *head;
	while (current != NULL)
	{
		// For each node, print proper number spaces before printing it
		for (int i = 0; i < 2 * (n - j); i++) //*2 because spaces will consume spaces too.
			printf(" ");

		// use of carriage return to move back
		// and print.
		printf("%d\r", current->data); // ! carriage return SYMBOL \r

		current = current->next;
		j++;
	}
}
//*
void push_forward(Node **head_ref, char new_data)
{

	Node *workingNode = new Node();
	workingNode->data = new_data;
	workingNode->next = *head_ref;
	*head_ref = workingNode;
}
int main()
{
	// Let us create linked list 1->2->3->4
	Node *head = NULL;
	push_forward(&head, 4);
	push_forward(&head, 3);
	push_forward(&head, 2);
	push_forward(&head, 1);
	cout << "Backward traversal using recursion is: \n";
	printReverse(head);
	cout << "\nForward traversal using recurion is: \n";
	printForwared(head);
	cout << "\nIterative forward raversal: \n";
	int n=printWithoutRecursion(head);
	cout << "\n Iterative Backward Traversal: \n";
	backPrintWithoutRecursion(&head, n);
	return 0;
}
