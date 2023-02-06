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
        bool insert(int position, int value) {

            // Array version:

                // if(position < 0){
                //     position = 0;
                // } else if (position > endOfList){
                //     position = endOfList;
                // }

                for(int i = 0; i < position; i++){
                    // iterate over nodes
                    temp = temp->nextNode;
                    cout << "temp: " << temp << endl;
                    
                }
                return true;

                // // shift later than position down one position
                // for(int i = endOfList; i >= position; --i){
                //     internalStorage[i] = internalStorage[i - 1];
                // }

                // internalStorage[position] = value;
                // endOfList++;

                // return true;

        }

        ArbitraryList(){}

        ArbitraryList(int size){
            front = nullptr;
            back = front;
            temp = front;
        }

    private:
        Node *front;
        Node *back;
        Node *temp; // temp is a pointer to a node
};