//1. stack.
/*
For implemntation using array.
* Pros: Easy to implement. Memory is saved as pointers are not involved.
* Cons: It is not dynamic. It doesn’t grow and shrink depending on needs at runtime.
*/
//2. stack using linked list.
/*
For implemetation using stack.
*Pros: The linked list implementation of stack can grow and shrink according to the needs at runtime.
*Cons: Requires extra memory due to involvement of pointers.
*/
//ARRAY BASED IMPLEMENTATION.
// mycodeschool : https://www.youtube.com/watch?v=sFVxsglODoo&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=15&ab_channel=mycodeschool
// gfg: https://www.geeksforgeeks.org/stack-data-structure-introduction-program/

// #include <bits/stdc++.h>
// using namespace std;
// #define max 1000
// class Stack
// {
//     int top = -1; // initially indicating empty stack. // we can go without class paradigm, and declare top and array as global variable.
// public:
//     int arr[max];     // max capacity of stack.
//     bool push(int x); // return is addedd or not.
//     bool isEmpty();
//     int pop();
//     int peek();
//     void size();
// };
// int Stack::peek()
// { // have access to private members of stack class.
//     if (top < 0)
//     {
//         cout << "empty stack";
//         return 0;
//     }
//     return arr[top];
// }
// bool Stack::push(int x)
// {
//     if (top >= max - 1) // zero based indexing
//     {
//         cout << "Stack Overflow";
//         return false;
//     }
//     arr[++top] = x;
//     cout << arr[top] << " pushed into stack ";
//     return true;
// }
// int Stack::pop()
// {
//     if (top < 0)
//     {
//         cout << "Stack Underflow";
//     }
//     else
//         return arr[--top];
// }
// bool Stack::isEmpty()
// {
//     // if(top<0)
//     // return true;
//     // else
//     // {
//     //     return false;
//     // }
//     return (top < 0);
// }
// void Stack::size()
// {
//     cout << "size of stack is " << top + 1;
// }
// int main()
// {
//     Stack obj;
//     obj.push(33);
//     cout << endl;
//     obj.size();
//     cout << endl;
//
//     obj.push(0);
//     cout << endl;
//
//     obj.size();
//     cout << endl;
//
//     obj.push(44);
//     cout << endl;
//
//     obj.size();
//     cout << endl;
//
//     obj.push(31);
//     cout << endl;
//
//     obj.size();
//     cout << endl;
//
//     obj.pop();
//     cout << endl;
//
//     obj.size();
//     cout << endl;
//
//     return 0;
// }
/*
* complexity:
For all the standard stack operations (push, pop, isEmpty, size), the worst-case run-time complexity can be O(1)
in worst case it can be o(n) when its about overflow, then we need to create a new stack of double size, copy everything to that new stack and come back.
*/

// LINKED LIST BASED IMPLEMNETATION.
// Reference : code: https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
//            diagram: https://www.javatpoint.com/ds-linked-list-implementation-of-stack
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = nullptr;
    }
};

node *newNode(int x)
{
    node *nd = new node(x);
    return nd;
}
bool isEmpty(node *root)
{
    return (!root);
}
void push(node **root, int data) // ! double pointer because we are passing by refrecne which is must and for that double pointer is required.
{
    node *temp = newNode(data);
    temp->next = *root; //* linked list ke front me push pop, coz if end it will be o(n)
    *root = temp;
    cout << data << " pushed to stack\n";
}
int pop(node **root)
{
    if (isEmpty(*root))
        return INT_MIN;
    node *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}
int peek(node **root)
{
    if (isEmpty(*root))
        return INT_MIN;
    return (*root)->data;
}

int main()
{
    node *root = nullptr;
    push(&root, 10);

    push(&root, 23);
    push(&root, 34);
    push(&root, 130);
    cout << "\nTop element is " << peek(&root) << endl;

    push(&root, 232);
    cout << "\nTop element is " << peek(&root) << endl;

    push(&root, 334);
    cout << isEmpty(root);
    cout << endl;
    cout << root->data;
    cout << endl;
    cout << pop(&root) << " popped from stack \n";
    cout << root->data;
    cout << "\nTop element is " << peek(&root) << endl;

    return 0;
}