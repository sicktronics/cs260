#pragma once
#include "BinarySearchTreeNode.h"

/*
* Parker Mayer
* CS 260
* 2/27/23
*/

// The BinarySearchTree class has methods for:
// -adding a value
// -printing the values in the tree using in-order traversal
// -searching for a value in the tree
// -finding the minimum value in the tree
// -finding the successor for a removal, and
// -removing a node.
// It has one member, a Node pointer that points to the root.
class BinarySearchTree {
    public:

        // Our constructor
        BinarySearchTree();

        // Our methods (more detailed comments in "BinarySearchTree.cpp").
        // For simplicity, each method has a version that the user calls, which in turn
        // calls the internal version. This makes updating the root node simpler.
        Node *addInternal(Node *node, int value);
        bool add(int value);
        void printInOrderTraversalInternal(Node *node);
        void printInOrderTraversal();
        Node *searchInternal(Node *node, int value);
        bool search(int value);
        int findMinInternal(Node *node);
        int findMin();
        int findSuccessorInternal(Node *node);
        int findSuccessor(int value);
        Node *removeInternal(Node *node, int value);
        bool remove(int value);
        
        // The root
        Node *root; 

};