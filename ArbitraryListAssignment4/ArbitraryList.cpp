#include <iostream>
#include <climits>
#include "Node.h"
#include "ArbitraryList.h"

// TODO
//  create headerfile
//  create readme
//  add comments
//  analyze complexity

using std::cout;
using std::endl;



class ArbitraryList {

    public:

        // This method allows us to insert a new node
        // into an arbitrary position in the list.
        bool insert(int value, int position) {

            Node *newNode = new Node(value, NULL, NULL);

            if(position < 0){
                position = 0;
            } else if (position > endPos){
                position = endPos;
            }

            if(front==nullptr){
                front = leftBound = rightBound = newNode;
            }else{

                if(position == 0) {

                    leftBound->prevNode = newNode;
                    newNode->nextNode = leftBound;
                    front = newNode;
                } else {

                    for(int i = position; i > 1; i--){
                    leftBound = leftBound->nextNode;
                }
                if(leftBound->nextNode == NULL){

                    leftBound->nextNode = newNode;
                    newNode->prevNode = leftBound;

                }else{
                    rightBound = leftBound->nextNode;

                    leftBound->nextNode = newNode;
                    rightBound->prevNode = newNode;

                    newNode->prevNode = leftBound;
                    newNode->nextNode = rightBound;
                }

                }

                
            }
            leftBound = rightBound = front;
            endPos++;
            return true;
        }

        // 
        bool remove(int position){

            if(position < 0){
                position = 0;
            } else if (position > endPos){
                position = endPos;
            }

            if(front==nullptr){

                return false;

            }else if(front->nextNode == NULL && front->prevNode == NULL){

                temp = front;
                leftBound = rightBound = front = nullptr;
                delete temp;
                return true;

            }else{

                if(position == 0) {
                    temp = front;
                    leftBound = front = front->nextNode;
                    delete temp;
                    
                } else {

                    for(int i = position; i > 1; i--){
                        leftBound = leftBound->nextNode;
                    }
                        rightBound = leftBound->nextNode;
                    

                        temp = leftBound;
                        rightBound->prevNode = leftBound->prevNode;
                        leftBound->prevNode->nextNode = rightBound;

                        delete temp;
                        endPos--;
                        leftBound = rightBound = front;
                }
                return true;
            }
        }

        // 
        int peek(int position){

            if(position < 0){
                position = 0;
            } else if (position > endPos){
                position = endPos;
            }
            
            if(front==nullptr){
                return INT_MIN;
            } else {
                for(int i = position; i > 1; i--){
                    leftBound = leftBound->nextNode;
                }
                int val = leftBound->value;
                leftBound = rightBound = front;
                return val;
            }
        }

        ArbitraryList(){
            front = nullptr;
            leftBound = front;
            rightBound = front;
            endPos = 0;
        }

    private:
        Node *front;
        Node *leftBound; // temp is a pointer to a node
        Node *rightBound;
        Node *temp;
        int endPos;     
};