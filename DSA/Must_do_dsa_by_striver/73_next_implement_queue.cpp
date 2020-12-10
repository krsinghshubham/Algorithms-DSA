//LEARNING: THIS PAGE WILL IMPROVE UR UNDERSTANDING OF OOPS TOO. -> IF HANDLIND WITH ADDRESS, . IF HANDLING WITH OBJECTS DIRECTLY.
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
at some point we may not we able to insert elements in the queue even if the queue is empty (this problem is avoided by using circular queue.( deque is different).

i.e., The space of the array, which is used to store queue elements, can never be reused to store the elements of that queue because the elements can only be
 inserted at front end and the value of front might be so high so that, all the space before that, can never be filled.
*/

//2.
//* Queue using linked list.
/*
For implemetation using Queue.
*Pros: 
The linked list implementation of Queue can grow and shrink according to the needs at runtime.
*Cons:
 Requires extra memory due to involvement of pointers.
*/

//* ARRAY BASED IMPLEMENTATION.
//
#include <iostream>
using namespace std;
class Queue
{
public:
    int front, rear; // pointners to front and rear of array.
    unsigned capacity;
    int size;
    int *array;
    void enqueue(Queue *q, int x);
};
Queue *createQueue(unsigned capacity)
{
    Queue *q = new Queue();
    q->capacity = capacity;
    q->array = new int[sizeof(int) * (q->capacity)]; //* q->capacity and not capacity.
    q->front = 0, q->size = 0;                       // front and size of array which will move dynamically;
    //q->rear = 0;    // last index this will work fine
    // but if we simply increment front and rear indices , then there may be problems, front may reach end of the array.
    // the solution of this problem is to increase the front and rear in circular mannner.
    //*so ...
    q->rear = q->capacity - 1; // will fix this in enqueue
    return q;
}
int isFull(Queue *queue)
{
    return (queue->size >= queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(Queue *queue)
{
    return (queue->size <= 0);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(Queue *q, int item) // not **queue becuase its array based implementation and not linked list based.
{
    if (isFull(q))
        return;
    // 1st increment the rear then
    // but if we simply increment front and rear indices , then there may be problems, front may reach end of the array.
    // the solution of this problem is to increase the front and rear in circular mannner.
    //*so ...
    q->rear = (q->rear + 1) % q->capacity; //! IMPORTANT STEP. PUTTING CIRCULAR MANNER.
    q->array[q->rear] = item;              // size of q
    q->size++;

    cout << item << " enqueued to queue\n";
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(Queue *q)
{
    if (isEmpty(q))
        return INT_MIN;
    int item = q->array[q->front]; // 1st get it and the head over.
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

// Function to get front of queue
int front(Queue *q)
{
    if (isEmpty(q))
        return INT_MIN;
    return q->array[q->front];
}

// Function to get rear of queue
int rear(Queue *q)
{
    if (isEmpty(q))
        return INT_MIN;
    return q->array[q->rear];
}
int main()
{
    Queue *queue = createQueue(1000);

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

//*  LINKED LIST BASED IMPLEMNETATION.

#include <iostream>
using namespace std;
class Node // to handle new nodes.
{
public:
    int data;
    Node *next;
    // in queue using linked list, pointer to front, and poitnere to rear.
    Node(int x)
    { // constructonr
        data = x;
        next = nullptr;
    }
};
class Queue
{
public:
    Node *front, *rear;
    Queue()
    {
        front = rear = nullptr;
    }
    void enQueue(int x)
    {
        Node *temp = new Node(x);
        if (rear == nullptr)
        {
            front = rear = temp;
            return;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
    void deQueue()
    {
        if (front == nullptr)
            return;

        // Store previous front and
        // move front one node ahead
        Node *temp = front;
        front = front->next;
        // what if next of front is null in above case.
        // means end of list.
        // !handle rear.
        if (front == nullptr)
            rear = nullptr;
        free(temp);
    }
};

int main()
{
    Queue q ;
    q.enQueue(10);
    q.enQueue(20);
    q.deQueue();
    q.deQueue();
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.deQueue();
    cout << "Queue Front : " << (q->front)->data << endl;
    cout << "Queue Rear : " << (q.rear)->data;
    return 0;
}
