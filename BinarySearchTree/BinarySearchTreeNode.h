#pragma once

/*
* Parker Mayer
* CS 260
* 2/27/23
*/

// The Node class has members for:
//  -the value it stores
//  -a pointer to its left child
//  -a pointer to its right child
//  -a pointer to its parent
class Node {
    public:
        int value;
        Node *left;
        Node *right;
        Node *parent;
};