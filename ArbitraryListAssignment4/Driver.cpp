#include <iostream>
#include "ArbitraryList.h"

/*
* Parker Mayer
* CS 260
* 2/6/2023
*/

using std::cout;
using std::endl;

int main(int argc, char **argv){

    ArbitraryList list; // Creating our list                            // O(1)

    // Test 1: Inserting, remove, and peek with one node
    cout << "Test 1: Adding, remove, and peek with one node" << endl;   // O(1)
    cout << "Insert successful?: " << list.insert(8, 0) << endl;        // O(n)
    cout << "Node at position 0: " << list.peek(0) << endl;             // O(n)
    cout << "Remove successful?: " << list.remove(0) << "\n\n" << endl; // O(n)

    // Test 2: Peeking at an empty list
    cout << "Test 2: Peeking at an empty list" << endl;                 // O(1)
    cout << "Empty list peek: " << list.peek(0) << "\n\n" << endl;      // O(n)

    // Test 3: Multiple insertions and removals
    cout << "Test 3: Multiple insertions and removals" << endl;         // O(1)
    cout << "Insert successful?: " << list.insert(8,0) << endl;         // O(n)
    cout << "Insert successful?: " << list.insert(9,1) << endl;         // O(n)
    cout << "Insert successful?: " << list.insert(10,2) << endl;        // O(n)
    cout << "Peek: " << list.peek(2) << endl; // Peeking at the "second" (index = 1) element
    cout << "Remove successful?: " << list.remove(0) << endl;           // O(n)
    cout << "Peek: " << list.peek(2) << endl;                           // O(n)
    cout << "Remove successful?: " << list.remove(0) << endl;           // O(n)
    cout << "Peek: " << list.peek(1) << endl;                           // O(n)
}