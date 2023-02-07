#include <iostream>
#include <climits>
#include "Node.h"
#include "ArbitraryList.h"

// TODO
//  create readme
//  analyze complexity

using std::cout;
using std::endl;

// This method allows us to insert a new node
// into an arbitrary position in the list.
bool ArbitraryList::insert(int value, int position) {

    // Creating the new node
    Node *newNode = new Node(value, NULL, NULL);

    // Keeping the position within the bounds of the list 
    // (originally implemented during a Week 4 lecture)
    if(position < 0){
        position = 0;
    } else if (position > endPos){
        position = endPos;
    }

    // If this is the first node to be inserted...
    if(front==nullptr){
        // ...set everything to point at the new node....
        front = leftBound = rightBound = newNode;
    
    // Otherwise, if there are already nodes in the list:
    }else{

        // (1) If we are inserting at the front...
        if(position == 0) {

            // Insert the new node before the current ("old") front.
            front->prevNode = newNode;
            newNode->nextNode = front;
            // Update the front.
            front = newNode;

        // (2) If we are inserting elsewhere in the list...
        } else {

            // Iterate over the list to the desired position.
            for(int i = position; i > 1; i--){
            leftBound = leftBound->nextNode;
            }

            // If we reach the end position...
            if(leftBound->nextNode == NULL){
                // Insert it into the "end" position
                leftBound->nextNode = newNode;
                newNode->prevNode = leftBound;

            }else{
                // Otherwise set the right bound to be next to the left bound
                rightBound = leftBound->nextNode;
                // Hook up the left and right to the new node.
                leftBound->nextNode = newNode;
                rightBound->prevNode = newNode;
                // Hook up the new node to the left and right.
                newNode->prevNode = leftBound;
                newNode->nextNode = rightBound;
            }
        }
    }
    // Then reset the left and right to point at the front.
    leftBound = rightBound = front;
    // Increment the end position.
    endPos++;
    // Return that the insertion was successful.
    return true;
}

// This method allows us to remove a node
// from an arbitrary position in the list.
bool ArbitraryList::remove(int position){

    // Quick checking of position validity.
    if(position < 0){
        position = 0;
    } else if (position > endPos){
        position = endPos;
    }

    // Return false if there aren't any nodes in the list
    if(front==nullptr){
        return false;

    // Otherwise if there's only one node in the list...
    }else if(front->nextNode == NULL && front->prevNode == NULL){

        // Empty the list of the node and return true.
        delete front;
        leftBound = rightBound = front = nullptr;
        return true;

    // Otherwise, if there's multiple nodes in the list...
    }else{

        // If we're removing the front node,
        // move the pointers to the "new front" and delete the old front
        if(position == 0) {
            temp = front;
            leftBound = rightBound = front = front->nextNode;
            delete temp;

        // For removing any other node.
        } else {

            // Shift the left bound to the position
            for(int i = position; i > 1; i--){
                leftBound = leftBound->nextNode;
            }            

            // If removing the end node
            if(leftBound->nextNode == NULL){
                temp = leftBound;
                // Sever the node from the end of the list
                leftBound->prevNode->nextNode = NULL;
                // Delete the old end node
                delete temp;
                // Reset the bounds.
                leftBound = rightBound = front;

            }else{
                // Otherwise set the right bound
                rightBound = leftBound->nextNode;
                temp = leftBound;

                // Hook up the right bound to the node before the left bound.
                rightBound->prevNode = leftBound->prevNode;
                leftBound->prevNode->nextNode = rightBound;

                // Delete the node.
                delete temp;
                // Decrement the end position.
                endPos--;
                // Reset the bounds.
                leftBound = rightBound = front;
            }
        }
        return true;
    }
}

// The peek method returns the value at a given position.
int ArbitraryList::peek(int position){

    // Keeping position in bounds.
    if(position < 0){
        position = 0;
    } else if (position > endPos){
        position = endPos;
    }
    
    // Return a value indicating we are dealing with an empty list.
    if(front == nullptr){
        return INT_MIN;
    // Otherwise iterate to the position and return the value.
    } else {
        for(int i = position; i > 1; i--){
            leftBound = leftBound->nextNode;
        }
        int val = leftBound->value;
        leftBound = rightBound = front;
        return val;
    }
}

// Constructor
ArbitraryList::ArbitraryList(){
    front = nullptr;
    leftBound = front;
    rightBound = front;
    endPos = 0;
}   
