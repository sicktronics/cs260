#include "element.h"

/*
* For the linked list, we use a class (rather than struct)
* so that we can have some private elements.
* 
* 
*/


template <typename ElemType> class LinkedList{
    public:
        // ...
        void enqueue(ElemType val){
            // ...
            Element<ElemType> *newElem = new Element<ElemType>(val, back);
            
            back = newElem;

            // figure this out
            // if(back->nextElem == nullptr){
            //     front = back;
            // }
        }

        // ...
        ElemType dequeue(){
            // Add handling for nullptr
            if(front == nullptr) {
                return -1;
            }

            // ...
            ElemType removed = front->value;
            Element<ElemType> *oldFront = front;
            front = front->nextElem;
            delete oldFront;
            return removed;
        }

        // ...
        ElemType peek(){
            // Add handling for nullptr
            if(front == nullptr) {
                return -1;
            }

            // ...
            return front->value;
        }

        // Constructor
        LinkedList(){
            front = nullptr;
            back = nullptr;
        }

    private:
        // Front and back pointers private so people don't mess with them.
        Element<ElemType> *back;
        Element<ElemType> *front;
};// End of LinkedList class.