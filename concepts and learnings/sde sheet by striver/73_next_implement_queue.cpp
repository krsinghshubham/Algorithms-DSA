//1. Queue.
/*
* For implemntation using array.
Complexity Analysis:

Time Complexity:
Operations              Complexity
Enque(insertion)           O(1)
Deque(deletion)            O(1)
Front(Get front)           O(1)
Rear(Get Rear)             O(1)              
Auxiliary Space: O(N).
N is the size of array for storing elements.
* Pros of Array Implementation:

Easy to implement.
* Cons of Array Implementation:

Static Data Structure, fixed size.
If the queue has a large number of enqueue and dequeue operations, 
at some point we may not we able to insert elements in the queue even if the queue is empty (this problem is avoided by using circular queue that is deque).

i.e., The space of the array, which is used to store queue elements, can never be reused to store the elements of that queue because the elements can only be
 inserted at front end and the value of front might be so high so that, all the space before that, can never be filled.
*/

#include <bits/stdc++.h>
using namespace std;
//#define max 1000
class Queue{ //Q should be capital.
public:
int front, rear, size;
unsigned capacity;
int * arr;
};
Queue* createQueue(unsigned capacity)
{   
    Queue *q= new Queue();
    q->capacity=capacity;
    // front and rear pointing to 1st and last index initally.
    q->front=q->size=0; // size will increment dynmacially in front direction only.
    q->rear=capacity-1; // rear element
    q->arr=  new int[sizeof(q->capacity)];
    return q;
}
int isFull(Queue* q)
{
    return (q->size>=q->capacity); //not -1 coz we are not accessing rear but accessing size.
}
int isEmpty(Queue* q)
{
    return (q->size<=0);
}
// Function to add an item to the queue. 
// It changes rear and size 
// void enqueue(Queue* queue, int item) 
// { 
//     if (isFull(queue)) 
//         return; 
//     queue->rear = (queue->rear + 1) 
//                   % queue->capacity; 
//     queue->arr[queue->rear] = item; 
//     queue->size = queue->size + 1; 
//     cout << item << " enqueued to queue\n"; 
// } 
void enqueue(Queue* q, int data)
{
    // adds in back...
    if(isFull(q))
    {
        cout<<"overflow\n";
        return;
    }
    
}
// Function to remove an item from queue. 
// It changes front and size 
int dequeue(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    int item = queue->arr[queue->front]; 
    queue->front = (queue->front + 1) 
                   % queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 
  
// Function to get front of queue 
int front(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->arr[queue->front]; 
} 
  
// Function to get rear of queue 
int rear(Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->arr[queue->rear]; 
} 
  

int main() 
{ 
    Queue* queue = createQueue(1000); 
  
    enqueue(queue, 10); 
    enqueue(queue, 20); 
    enqueue(queue, 30); 
    enqueue(queue, 40); 
  
    cout << dequeue(queue) 
         << " dequeued from queue\n"; 
  
    cout << "Front item is "
         << front(queue) << endl; 
    cout << "Rear item is "
         << rear(queue) << endl; 
  
    return 0; 
} 
//* Queue using linked list.
/*
For implemetation using Queue.
*Pros: 
The linked list implementation of Queue can grow and shrink according to the needs at runtime.
*Cons:
 Requires extra memory due to involvement of pointers.
*/


//* ARRAY BASED IMPLEMENTATION.




//*  LINKED LIST BASED IMPLEMNETATION.