#include <iostream>
#include <string>
#include "SmartHashTable.h"

// The default constructor starts with a table capacity of 16
SmartHashTable::SmartHashTable() {
    // Resizing vector, setting capacity
    table.resize(16);
    capacity = 16;
    // Initializing our stat variables
    collisionCount = 0;
    size = 0;
    insertCount = 0;
}

// This constructor allows for a custom starting capacity
SmartHashTable::SmartHashTable(int size) {
    // Resizing the vector and setting up the capacity
    table.resize(size);
    capacity = size;
    // Initializing our stat variables
    size = 0;
    collisionCount = 0;
    insertCount = 0;
}

// The "smart" insert method takes a string, hashes it and checks for collisions
// If initial collision, runs the double hashing method and performs final collision check
// (with the hopes that the collision was resolved). Returns whether collision ultimately occurred.
bool SmartHashTable::insert(string value) {

    // Hash to find the insertion position in the vector (the student's "ID" number)
    int candidatePos = hash(value);
    // Initialize new position in case double hashing is needed
    int newCandidatePos = 0;

    // Collision is false by default (may get updated)
    bool collision = false;

    // Shows the value currently stored at the candidate position (collision if a different "last name" already lives there)
    // std::cout << "table.at(" << candidatePos << "): " << "\"" << table.at(candidatePos) << "\"" << std::endl;

    // If there is a collision...
    if (table.at(candidatePos) != value && table.at(candidatePos) != "") {
        
        // Use double hashing to generate a new candidate position, update the position to reflect new index
        newCandidatePos = doubleHash(value, candidatePos);
        candidatePos = newCandidatePos;

        // Re-check if there is still a collision with new ID number and update stats if needed
        if(table.at(newCandidatePos) != value && table.at(candidatePos) != "") {
            collision = true;
            collisionCount++;
        }
    }

    // Place the value in the table
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
string SmartHashTable::search(string value) {
    return table.at(hash(value));
}

// The remove method takes a student's last name and, if it's in the hashtable,
// removes it. Returns whether removal was successful.
bool SmartHashTable::remove(string value) {
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
int SmartHashTable::hash(string value) {

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

// I designed the doubleHash method using some principles from a tutorial 
// (see "Resources Used" section of README)

// The doubleHash method generates an updated "ID number" index in the
// hopes of decreasing number of collisions. Takes the old ID number and
// the to-be-hashed string, and returns the new hash value.
int SmartHashTable::doubleHash(string value, int oldStudentIDNum){

    // Initialize second ID number
    int newStudentIDNum = 0;

    // Take the (slightly altered) ASCII sum of characters in the last name
    for(char& curr : value) {
        newStudentIDNum += curr - 'A' + 2; // Bumping up the values a small amount
    }

    // This returns a value between 0 and capacity - 1
    newStudentIDNum %= getCapacity();

    // Next, create a new hash by combining the old ID number with the product of the 
    // new ID number and the number of collisions (+1 so not multiplying by zero)
    int comboHash = (oldStudentIDNum + ((1+collisionCount)*newStudentIDNum)) % getCapacity(); 

    // Return the new ID number
    return comboHash;
}

// Getter method to return current capacity
int SmartHashTable::getCapacity() {return capacity;}

// Getter method to return current size
int SmartHashTable::getSize() {return size;}

// Getter method to return "fullness" (size / capacity)
float SmartHashTable::getFullness() {
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
int SmartHashTable::getInsertCount(){return insertCount;}

// Getter method to return number of collisions
int SmartHashTable::getCollisionCount(){return collisionCount;}

// toString method steps through the hashtable and prints out the student name-ID number pairs
string SmartHashTable::toString(){
    string result = "[";

    for(int key = 0; key < getCapacity(); ++key){
        result += "(" + std::to_string(key) + "," + table.at(key) + ")";
    }

    result += "]";
    return result;
}