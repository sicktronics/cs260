#pragma once
/*
* This templated struct (public by default) stores information
* on a single "element" that will live in our linked list.
*
* The template allows the linked list to manage different
* data types.
*/ 

template <typename ElemType> struct Element{

    // An element has two attributes:
    ElemType value;     // (1) The value it holds,
    Element *nextElem;  // (2) A pointer to the address of the next element.

    Element() {}    // Default constructor
    
    // Our constructor that takes the two attributes.
    Element(ElemType val, Element *nxt) {
        this->value = val;
        this->nextElem = nxt;
    }
};  // End of Element struct.