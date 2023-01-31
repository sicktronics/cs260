// #include <optional>
#include "element.h"

/*
* For the linked list, we use a class (rather than struct)
* so that we can have some private elements.
* There are three methods: enqueue, dequeue, and peek.
*/

// The LinkedList class
template <typename ElemType> class LinkedList{

    public:

        // NOTE: At time of submission, still trying to implement
        // optional for better handling of different data types
        // in the dequeue and peek methods (see below).
        // std::optional<ElemType> opt = -1;

        // Enqueue method allows us to add a new element to the back of the queue
        void enqueue(ElemType val){

            // Creating a pointer to our new element
            Element<ElemType> *newElem = new Element<ElemType>(val, NULL);

            // If this is the first element being added,
            // it is both the 'front' and 'back' element 
            if(back==nullptr){
                front = newElem;
                back = newElem;
            }
            // The 'nextElem' field of the back now points to this new element
            back->nextElem = newElem;
            // Then we shift the back to the "back" of the queue
            back = newElem;
        }

        // Dequeue method allows us to remove an element from the front of the queue
        ElemType dequeue(){

            // Return -1 if empty (note that this will cause
            // errors if ElemType is not an int....Working on
            // a fix).
            if(front == nullptr) {
                // return opt.value();
                return -1;
            } 



            // Grab the value currently at the front to return it
            ElemType removed = front->value;
            // Temporarily store the front
            Element<ElemType> *oldFront = front;
            // If we're about to remove the last element in the queue, reset to null (empty queue).
            // Otherwise, move the front to the next element in the queue if we're not about to remove the final element.
            if(front==back){
                front=nullptr;
                back = nullptr;
            } else {
                front = front->nextElem;
            }
            // Delete the old front element.
            delete oldFront;

            // Return the removed value
            return removed;
        }

        // The peek method returns the value of the front element.
        ElemType peek(){
            // Return -1 if empty (note that this will cause
            // errors if ElemType is not an int....Working on
            // a fix).
            if(back == nullptr) {
                // return opt.value();
                return -1;
            }
            return front->value;
        }

        // Constructor
        LinkedList(){
            front = nullptr;
            back = front;
        }

    private:
        // Front and back pointers private so people don't mess with them.
        Element<ElemType> *back;
        Element<ElemType> *front;
};// End of LinkedList class.