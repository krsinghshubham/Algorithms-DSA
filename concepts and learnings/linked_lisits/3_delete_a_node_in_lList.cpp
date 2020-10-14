// A program to delete a node in a linked list at a given position
#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
};
/* Given a reference (pointer to pointer) to the head of a list. */
void push_front(Node **head, int data)
{
    Node *workNode = new Node();

    workNode->value = data;
    workNode->next = *head;
    *head = workNode;
}
void deleteNode(Node **head, int position)
{
    // If linked list is empty
    if (*head == NULL)
        return;
    // Store head node
    Node *temp = *head;
    if (position == 0)
    {
        *head = temp->next; // Change head
        free(temp);         // free old head
        return;
    }
    // Find previous node of the node to be deleted
    // for (int i = 0; temp != NULL && i < position - 1; i++)
    for (int i = 0; temp != nullptr && i < position - 1; i++)
    {
        temp = temp->next;
    }
    cout << "\n"
         << temp->value << endl;
            cout << "\n"
         << temp->next->value << endl;
    // * by this iteration temp will have null if crosses last pointer...
    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    //* wrong way
    // temp->next= temp->next->next;     // because memory not cleared
    // free(temp->next); // Free memory but what if its the not the last node, then traversing will go infinte.
    //*
    //
    //* correct way....
    Node * temporaryNode= temp->next->next;
    free(temp->next);
    temp->next=temporaryNode;
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
    struct Node *head = NULL;
    push_front(&head, 7);
    push_front(&head, 1);
    push_front(&head, 3);
    push_front(&head, 2);
    push_front(&head, 8);
    push_front(&head, 3);
    puts("Created Linked List: ");
    printList(head);
    deleteNode(&head, 4);
    puts("\nLinked List after Deletion at position 4: ");
    printList(head);
    return 0;
}
