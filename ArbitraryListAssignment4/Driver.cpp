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

    ArbitraryList list; // Creating our list

    // Test 1: Inserting, remove, and peek with one node
    cout << "Test 1: Adding, remove, and peek with one node" << endl;
    cout << "Insert successful?: " << list.insert(8, 0) << endl;
    cout << "Node at position 0: " << list.peek(0) << endl;
    cout << "Remove successful?: " << list.remove(0) << "\n\n" << endl;

    // Test 2: Peeking at an empty list
    cout << "Test 2: Peeking at an empty list" << endl;
    cout << "Empty list peek: " << list.peek(0) << "\n\n" << endl;

    // Test 3: Multiple insertions and removals
    cout << "Test 3: Multiple insertions and removals" << endl;
    cout << "Insert successful?: " << list.insert(8,0) << endl;
    cout << "Insert successful?: " << list.insert(9,1) << endl;
    cout << "Insert successful?: " << list.insert(10,2) << endl;
    cout << "Peek: " << list.peek(2) << endl;
    // cout << "Peek nonexistent spot: " << list.peek(7) << endl;
    cout << "Remove successful?: " << list.remove(0) << endl;
    cout << "Remove successful?: " << list.remove(9) << endl;
    cout << "Peek: " << list.peek(0) << endl;
}