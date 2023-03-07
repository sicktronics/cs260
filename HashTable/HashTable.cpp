#include <iostream>
#include <string>
#include "HashTable.h"

// The default constructor starts with a table capacity of 16
HashTable::HashTable() {
    // Resizing vector, setting capacity
    table.resize(16);
    capacity = 16;
    // Initializing our stat variables
    collisionCount = 0;
    size = 0;
    insertCount = 0;
}

// This constructor allows for a custom starting capacity
HashTable::HashTable(int size) {
    // Resizing the vector and setting up the capacity
    table.resize(size);
    capacity = size;
    // Initializing our stat variables
    size = 0;
    collisionCount = 0;
    insertCount = 0;
}

// The insert method takes a to-be-insertted string and returns whether there was a collision
bool HashTable::insert(string value) {

    // Hash to find the insertion position in the vector (the student's "ID" number)
    int candidatePos = hash(value);

    // Collision is false by default (may get updated)
    bool collision = false;

    // Shows the value currently stored at the candidate position (collision if a different "last name" already lives there)
    // std::cout << "table.at(" << candidatePos << "): " << "\"" << table.at(candidatePos) << "\"" << std::endl;

    // Check for collision
    if(table.at(candidatePos) != value && table.at(candidatePos) != "") {
        // Update stats to reflect that a collision occurred
        collision = true;
        collisionCount++;
    }

    // Regardless of collision status, place the passed-in value at the "ID number" index
    table.at(candidatePos) = value;

    // If no collsion, update size variable
    if(collision == false) {
        size++;
    }
    // Update number of insertions
    insertCount++;
    // Return whether collision occurred
    return collision;
}

// The search method takes a student's last name and returns what is
// currently at the corresponding index in the hashtable
string HashTable::search(string value) {
    return table.at(hash(value));
}

// The remove method takes a student's last name and, if it's in the hashtable,
// removes it. Returns whether removal was successful.
bool HashTable::remove(string value) {
    // Find hash
    int candidatePosition = hash(value);
    // Check if the name that lives at that position in the hashtable is what
    // we want to remove. If it is, remove it!
    if (table.at(candidatePosition) == value) {
        table[candidatePosition] = "";
        // Update size, and return successful removal
        size--;
        return true;
    }
    // Otherwise return unsuccessful removal
    return false;
}

// This hash function is the same as what we built in class
// (except dealing with uppercase letters).
// Given a student's last name, sum up the ASCII values
// associated with each character in the string, get it in range by
// modulo-ing it by the capacity of the table. This becomes the
// Student's "ID number" as well as the index in the hashtable
// at which it will be stored.
int HashTable::hash(string value) {

    int studentIDNum = 0;

    // Assume all uppercase values
    for(char& curr : value) {
        studentIDNum += curr - 'A' + 1;
    }

    // This returns a value between 0 and capacity - 1
    studentIDNum %= getCapacity();

    // Return the ID number
    return studentIDNum;
}

// Getter method to return current capacity
int HashTable::getCapacity() {return capacity;}

// Getter method to return current size
int HashTable::getSize() {return size;}

// Getter method to return "fullness" (size / capacity)
float HashTable::getFullness() {
    int cap = getCapacity();
    float result = 0.0f;
    if(cap != 0) {
        result = ((float)size / (float)cap);
    } else {
        result = -1;
    }
    return result;
}

// Getter method to return number of inserts
int HashTable::getInsertCount(){return insertCount;}

// Getter method to return number of collisions
int HashTable::getCollisionCount(){return collisionCount;}

// toString method steps through the hashtable and prints out the student name-ID number pairs
string HashTable::toString(){
    string result = "[";

    for(int key = 0; key < getCapacity(); ++key){
        result += "(" + std::to_string(key) + "," + table.at(key) + ")";
    }

    result += "]";
    return result;
}

