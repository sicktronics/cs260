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

// The constructor initially sets the root to a nullpointer.
BinarySearchTree::BinarySearchTree(){
    root = nullptr;
}

// The "internal" add method takes a node and a value
// and returns the updated node.
Node *BinarySearchTree::addInternal(Node *node, int value){
    
    // If our tree doesn't exists or there's no child, then
    // update the node's value and set other variables to null.
    if(node == nullptr){
        node = new Node;
        node->value = value;
        node->left = nullptr;
        node->right = nullptr;
        node->parent = nullptr;
    }

    // If given value is greater than node's value... 
    else if(node->value < value){

        // ...move on to right subtree.
        node->right = addInternal(node->right, value);

        // When the placement is complete, it returns here and updates the link to
        // The parent node.
        node->right->parent = node;
    }
    // Otherwise, if the given value is less than or equal to the node's value...
    else {
        // ...move on to the left subtree.
        node->left = addInternal(node->left, value);

        // When the placement is complete, it returns here and updates the link to
        // The parent node.
        node->left->parent = node;
    }

    // Finally, return the node
    // This helps us update the root when, say, we are placing a node for the first time.
    return node;
}

// This add method is what the user calls.
// They pass in a value that they want to add,
// and the method passes that value and the root to the
// internal method.
bool BinarySearchTree::add(int value){
    root = addInternal(root, value);

    // Return successful insertion.
    return true;
}

// The "internal" printInOrderTraversal method takes a node
// and traverses the tree in-order printing values along the way.
void BinarySearchTree::printInOrderTraversalInternal(Node *node){

    // If the node is null, return up one level.
    if(node == nullptr){
        return;
    }

    // Get the smallest value for a subtree
    printInOrderTraversalInternal(node->left);
    // Print out values along the way...
    cout << node->value << " ";
    // Continue on to the greatest value of a subtree
    printInOrderTraversalInternal(node->right);
}

// This printInOrderTraversal method is called by the user, which in turn
// calls the internal method and passes the root. Finally, it ends the output line.
void BinarySearchTree::printInOrderTraversal(){
    printInOrderTraversalInternal(root);
    cout << endl;
}

// The "internal" search method takes a node and a value to 
// search for, and returns the result of the search.
Node *BinarySearchTree::searchInternal(Node *node, int value){

    // Return nullpointer if the node is null.
    if(node == nullptr){
        return nullptr;
    // If we land on the value, return the node.
    } else if(node->value==value){
        return node;
    // If the value is greater than the node's value,
    // Search the right subtree
    } else if(node->value < value){
        return searchInternal(node->right, value);
    // If the value is less than the node's value,
    // Search the left subtree
    } else {
        return searchInternal(node->left, value);
    }
}

// This search method is called by the user, and takes a value to search for
bool BinarySearchTree::search(int value){

    // Store the result of the search
    Node *foundNode = searchInternal(root, value);
    
    // Check the returned node, and return whether the search was successful
    if(foundNode == nullptr){
        return false;
    } else {
        return true;
    }
}

// The "internal" findMin method takes a node
// and returns the value of the leftmost node.
// (We use this in finding the successor).
int BinarySearchTree::findMinInternal(Node *node){

    // If the node is null, terminate.
    if(node == nullptr){
        return -1;
    // Return the value if there is no left node (meaning we found the smallest value)
    } else if(node->left == nullptr){
        return node->value;

    // Otherwise keep going left!
    } else {
        return findMinInternal(node->left);
    }
}

// This findMin method is called by the user and
// passes the root to the internal method.
int BinarySearchTree::findMin(){
    return findMinInternal(root);
}

/*
    Rules of successor method:
        If the value has right subtree -> successor is min value in right subtree.
        If the value has no right subtree -> go back until you find first node that's greater than it.
        If the value is the max value in tree -> no successor, you can just remove it. 
*/

// The "internal" findSuccessor method takes a node to be removed
// and returns the value of the successor node.
int BinarySearchTree::findSuccessorInternal(Node *node){

    // If the value has a right subtree, the successor is the minimum value in the right subtree.
    if(node->right != nullptr){
        return findMinInternal(node->right);
    
    } else {

        // Otherwise, if there's no right subtree, store the current node and the parent...
        Node *parentNode = node->parent;
        Node *currentNode = node;

        // ...while current node is not the root and is a right child, keep going up
        while((parentNode != nullptr) && (currentNode == parentNode->right)){
            currentNode = parentNode;
            parentNode = currentNode->parent;
        }

        // If parent node is not null, it is the successor.
        if(parentNode == nullptr){
            return -1;
        } else{
            return parentNode->value;
        }
    }
}

// This findSuccessor method takes a value
// and returns the result of the successor search.
int BinarySearchTree::findSuccessor(int value){
    // First, determine if the node exists.
    Node *valueNode = searchInternal(root, value);

    // If the node exists, pass it to the internal method
    // and return the result.
    if(valueNode == nullptr){
        return -1;
    } else {
        return findSuccessorInternal(valueNode);
    }
}

// The "internal" remove method takes a node and a value to be removed
// and returns the resulting node.
Node *BinarySearchTree::removeInternal(Node *node, int value){

    // If the node isn't in our BST, return nullpointer.
    if(node == nullptr){
        return nullptr;
    }

    // If we landed on the node that contains the value we want to remove...
    if(node->value == value){

        //...check if it's a leaf; if so, remove it w/o successor
        if(node->left == nullptr && node->right == nullptr){
            node = nullptr;

        // Otherwise, if the node only has a right child,
        } else if(node->left == nullptr && node->right != nullptr){
            // hook the child up to the current node's parent, bypassing it.
            node->right->parent = node->parent;
            node = node->right;

        // Otherwise, if the node only has a left child,
        } else if(node->left != nullptr && node->right == nullptr){
            // hook the child up to the current node's parent, bypassing it.
            node->left->parent = node->parent;
            node = node->left;
        
        // Otherwise, if the node has two children, 
        } else {
            // we pass it to the findSuccessor method and store the value,
            int successorValue = findSuccessor(value);
            // update its value to the successor value,
            node->value = successorValue;
            // and update the right child.
            node->right = removeInternal(node->right, successorValue);
        }

    // If the node's value is smaller than what we're looking for,
    // move on to (and eventually update) the right subtree
    } else if(node->value < value){
        node->right = removeInternal(node->right, value);

    // If the node's value is larger than what we're looking for,
    // move on to (and eventually update) the left subtree
    } else {
        node->left = removeInternal(node->left, value);
    }

    // Return the resulting node.
    return node;
}

// This remove method takes an int (the value we want to remove),
// and in turn passes the root and that value to the internal method.
bool BinarySearchTree::remove(int value){
    
    // Checking to make sure the tree exists.
    if(root == nullptr){
        return false;
    }
    
    root = removeInternal(root, value);

    // Return successful execution status.
    return true;
}