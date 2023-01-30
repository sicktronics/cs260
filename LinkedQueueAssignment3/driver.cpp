#include <iostream>
#include "element.h"
#include "linked_list.h"

/*
* Parker Mayer
* CS 260
* 1/29/23
* Assignment 3: Linked Queue
*/

using std::cout;
using std::endl;

int main(int argc, char **argv) {

    LinkedList<int> queue;

    // Tests

    // Test 1: Adding/removing one element
    cout << "Test 1: Adding/removing one element." << endl;
    queue.enqueue(6);
    cout << "   Front element: " << queue.peek() << endl;
    queue.dequeue();
    cout << "   Front element: " << queue.peek() << endl;

    // Test 2: Adding/removing multiple elements
    cout << "Test 2: Adding/removing multiple elements." << endl;
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(9);
    cout << "   Front element: " << queue.peek() << endl;
    queue.dequeue();
    cout << "   Front element: " << queue.peek() << endl;
    queue.dequeue();
    cout << "   Front element: " << queue.peek() << endl; 
    queue.dequeue();
    cout << "   Front element: " << queue.peek() << endl;    

}

// Assignment 3 (Linked Queue):
// 1. Based on what we know about linked lists, stacks, and queues, design a linked queue 
//    (a queue using a linked-list to store the data in the structure)

// 2. Design, implement, and test a Queue data structure that:

//  (a) uses a linked-list to store values in the queue

//  (b) has an enqueue method that will appropriately add a value to the back of the queue as an appropriate element

//  (c) has a dequeue method that will appropriately remove an element from the front of the queue and return its value

//  (d) Optionally has a peek method that returns the value at the front of the queue without removing it
//      Bonus if you also create an array based Queue!

// 3. Analyze the complexity of your implementations (at least the run-time of the add, remove, and peek methods).
//    (Note that we will often consider operations not having to do with the structure as O(1), even if they might be expensive 
//    operations in terms of real-time or space used)
//    (Note that if you are not in class when we talk about Asymptotic Big-O notation, you can find tons of good examples online)

// 4. Tests: Be sure to include at least one test for each piece of functionality that should verify that your code is working!

// 5. Be sure to commit changes regularly to your git repo

// 6. Once you have implemented and tested your code, add to the README file what line(s) of code or inputs and 
//    outputs show your work meeting each of the above requirements (or better, include a small screen snip of where it meets the requirement!).

// 7. Remember to submit a link to this project in Moodle to remind us to grade it!

// Note: This assignment is partly to get you some practice with basic pointers if you have not used them much, to get you thinking about dynamically 
// sizing containers, and to think about what might be efficient and what might be able to be improved.
