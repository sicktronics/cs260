#include <iostream>

#include "BinarySearchTreeNode.h"
#include "BinarySearchTree.h"

/*
* Parker Mayer
* CS 260
* 2/27/23
*/

using std::cout;
using std::endl;

// Main method containing our tests
int main(int argc, char **argv) {

    BinarySearchTree bst;

    // Test 1: Adding, traversing, and removing one node
    cout << "Test 1: Adding, traversing, and removing one node" << endl;
    cout << "Status of adding: " << bst.add(14) << endl;
    cout << "Current nodes: ";
    bst.printInOrderTraversal();
    cout << "Status of removing: " << bst.remove(14) << endl;
    cout << "Current nodes: "; 
    bst.printInOrderTraversal();
    cout << "Test complete." << endl;
    cout << "\n" << endl;

    // Test 2: Removing node from empty tree
    cout << "Test 2: Removing node from empty tree" << endl;
    cout << "Status of removing: " << bst.remove(900) << endl;
    cout << "Test complete." << endl;
    cout << "\n" << endl;

    // Test 3: Adding, traversing, and removing multiple nodes
    cout << "Test 3: Adding, traversing, and removing multiple nodes" << endl;
    cout << "Status of adding: " << bst.add(7) << endl;
    cout << "Status of adding: " << bst.add(20) << endl;
    cout << "Status of adding: " << bst.add(1) << endl;
    cout << "Status of adding: " << bst.add(33) << endl;
    cout << "Status of adding: " << bst.add(55) << endl;
    cout << "Status of adding: " << bst.add(3) << endl;
    cout << "Status of adding: " << bst.add(100) << endl;
    
    bst.printInOrderTraversal();

    cout << "Status of removing: " << bst.remove(1) << endl;
    cout << "Status of removing: " << bst.remove(20) << endl;

    bst.printInOrderTraversal();
    cout << "Test complete." << endl;
    cout << "\n" << endl;

    // Test 4: Searching for values & finding the minimum value
    cout << "Test 4: Searching for values & finding the minimum value" << endl;
    cout << "Searching for 33: " << bst.search(33) << endl;
    cout << "Searching for 1000: " << bst.search(1000) << endl;
    cout << "Finding the min: " << bst.findMin() << endl;
    cout << "Test complete." << endl;
    cout << "\n" << endl;

    return 0;
}