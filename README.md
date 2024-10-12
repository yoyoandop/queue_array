Queue Implementation in C++
Description
This is a basic implementation of a queue data structure using a fixed-size array in C++. It does not use any external libraries such as std::queue. The implementation utilizes a circular queue to efficiently manage the space when elements are added and removed.

Features:
Enqueue: Add an element to the rear of the queue.
Dequeue: Remove an element from the front of the queue.
Peek: View the element at the front without removing it.
Circular Queue Logic: Effectively reuses array space using modular arithmetic.
Queue Capacity Management: Detects when the queue is full or empty.