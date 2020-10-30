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
//*ARRAY BASED IMPLEMENTATION.
/* C++ program to implement basic stack 
operations */
// #include <bits/stdc++.h> 
// 
// using namespace std; 
// 
// #define MAX 1000 
// 
// class Stack { 
// 	int top; 
// 
// public: 
// 	int a[MAX]; // Maximum size of Stack 
// 
// 	Stack() { top = -1; } 
// 	bool push(int x); 
// 	int pop(); 
// 	int peek(); 
// 	bool isEmpty(); 
// }; 
// 
// bool Stack::push(int x) 
// { 
// 	if (top >= (MAX - 1)) { 
// 		cout << "Stack Overflow"; 
// 		return false; 
// 	} 
// 	else { 
// 		a[++top] = x; 
// 		cout << x << " pushed into stack\n"; 
// 		return true; 
// 	} 
// } 
// 
// int Stack::pop() 
// { 
// 	if (top < 0) { 
// 		cout << "Stack Underflow"; 
// 		return 0; 
// 	} 
// 	else { 
// 		int x = a[top--]; 
// 		return x; 
// 	} 
// } 
// int Stack::peek() 
// { 
// 	if (top < 0) { 
// 		cout << "Stack is Empty"; 
// 		return 0; 
// 	} 
// 	else { 
// 		int x = a[top]; 
// 		return x; 
// 	} 
// } 
// 
// bool Stack::isEmpty() 
// { 
// 	return (top < 0); 
// } 
// 
// int main() 
// { 
// 	class Stack s; 
// 	s.push(10); 
// 	s.push(20); 
// 	s.push(30); 
// 	cout << s.pop() << " Popped from stack\n"; 
// 
// 	return 0; 
// } 




//* LINKED LIST BASED IMPLEMNETATION.
// tutorial : code: https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
//            diagram: https://www.javatpoint.com/ds-linked-list-implementation-of-stack
// C++ program for linked list implementation of stack 
#include <bits/stdc++.h> 
using namespace std; 

// A structure to represent a stack 
class StackNode { 
public: 
	int data; 
	StackNode* next; 
}; 

StackNode* newNode(int data) 
{ 
	StackNode* stackNode = new StackNode(); 
	stackNode->data = data; 
	stackNode->next = NULL; 
	return stackNode; 
} 

int isEmpty(StackNode* root) 
{ 
	return !root; 
} 

void push(StackNode** root, int data) 
{ 
	StackNode* stackNode = newNode(data); 
	stackNode->next = *root; 
	*root = stackNode; 
	cout << data << " pushed to stack\n"; 
} 

int pop(StackNode** root) 
{ 
	if (isEmpty(*root)) 
		return INT_MIN; 
	StackNode* temp = *root; 
	*root = (*root)->next; 
	int popped = temp->data; 
	free(temp); 

	return popped; 
} 

int peek(StackNode* root) 
{ 
	if (isEmpty(root)) 
		return INT_MIN; 
	return root->data; 
} 

int main() 
{ 
	StackNode* root = NULL; 

	push(&root, 10); 
	push(&root, 20); 
	push(&root, 30); 

	cout << pop(&root) << " popped from stack\n"; 

	cout << "Top element is " << peek(root) << endl; 

	return 0; 
} 
