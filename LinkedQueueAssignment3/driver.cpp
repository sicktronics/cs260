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