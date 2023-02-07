#include "Node.h"

// The Arbitrary List class has three methods:
// "insert" allows you to insert a value at a given position
// "remove" allows you to remove a value at a given position
// "peek" returns the value at a given position.
class ArbitraryList{
    public:
        ArbitraryList();
        bool insert(int value, int position);
        bool remove(int position);
        int peek(int position);
        
    private:
        // These class variables are pointers to the front of the list,
        // as well as "bounds" that help zero in on a given node.
        // Temp is used to temporarily store nodes.
        Node *front;
        Node *leftBound;
        Node *rightBound;
        Node *temp;
        
        int endPos;   // This tracks the "end position" of the list.
};