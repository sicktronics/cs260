#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

/*
* Parker Mayer
* CS 260
* 3/6/2023
*/

class HashTable {
    public:
        // Constructors
        HashTable();
        HashTable(int initialSize);

        // Our insert, search, and remove methods
        bool insert(string value);
        string search(string value);
        bool remove(string value);

        // Our hashing method
        int hash(string value);

        // Method for printing out the hashtable values
        string toString();

        // Getter methods for returning various hashtable stats
        int getCapacity();
        int getSize();
        float getFullness();
        int getInsertCount();
        int getCollisionCount();

    private:
        // The hashtable "vector" and variables to track size, capacity,
        // number of inserts, and number of collisions
        vector<string> table;
        int size;
        int capacity;
        int insertCount;
        int collisionCount; 
};
