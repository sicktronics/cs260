#include <iostream>
#include "Node.h"
#include "ArbitraryList.h"

// The idea is that you move on down the list 'x' times (for loop, merhaps?)

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

        // ArbitraryList(){}

        ArbitraryList(){
            front = nullptr;
            leftBound = front;
            rightBound = front;
            endPos = 0;
        }

    // private:
        Node *front;
        Node *leftBound; // temp is a pointer to a node
        Node *rightBound;
        int endPos;
        
};