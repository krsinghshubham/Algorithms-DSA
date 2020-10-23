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




//*  LINKED LIST BASED IMPLEMNETATION.