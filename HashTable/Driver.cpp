#include <iostream>

#include "HashTable.h"
#include "SmartHashTable.h"

using std::cout;
using std::endl;

/*
* Parker Mayer
* CS 260
* 3/6/2023
*/

// Tests are run in the main method
int main(int argc, char **argv){

    // Creating our normal hash table
    HashTable ht(10);

    // Test 1: ("Dumb" HashTable) - Insert, search, and remove one student from the table
    cout << "Test 1: (\"Dumb\" HashTable) - Insert, search, and remove one student from the table\n-----" << endl;
    ht.insert("SMITH");
    cout << "Table after insert: " << ht.toString() << endl;
    cout << "Searching for \"SMITH\": " << ht.search("SMITH") << endl;
    ht.remove("SMITH");
    cout << "Table after remove: " << ht.toString() << endl;
    cout << endl;

    // Test 2: ("Dumb" HashTable) - Insert, print stats on, search, remove multiple students from the table
    cout << "Test 2: (\"Dumb\" HashTable) - Insert, print stats on, search, remove multiple students from the table\n-----" << endl;

    ht.insert("HERNANDEZ");
    ht.insert("JOHNSON");
    ht.insert("MAYER");
    ht.insert("SINGH");
    ht.insert("BROWN");
    cout << "Table after inserts: " << ht.toString() << endl;
    cout << "Number of collisions during inserts: " << ht.getCollisionCount() << endl;
    cout << "Searching for \"BROWN\": " << ht.search("BROWN") << endl;
    cout << "Searching for \"HERNANDEZ\": " << ht.search("HERNANDEZ") << endl;
    ht.remove("JOHNSON");
    ht.remove("SINGH");
    ht.remove("BROWN");
    cout << "Table after removes: " << ht.toString() << endl;
    cout << endl;

    // Test 3: ("Dumb" HashTable) - Overwriting a student
    cout << "Test 3: (\"Dumb\" HashTable) - Overwriting a student\n-----" << endl;

    HashTable ht2(5);
    cout << "Inserting \"JOHNSON\"..." << endl;
    ht2.insert("JOHNSON");
    cout << "Searching for \"JOHNSON\": " << ht2.search("JOHNSON") << endl;
    cout << "Inserting \"HERNANDEZ\"..." << endl;
    ht2.insert("HERNANDEZ");
    cout << "Searching for \"HERNANDEZ\": " << ht2.search("HERNANDEZ") << endl;
    cout << "Number of collisions during inserts: " << ht2.getCollisionCount() << endl;
    cout << endl;

    // Test 4: ("Dumb" HashTable) - Retrieving stats for a table of multiple students
    cout << "Test 4: (\"Dumb\" HashTable) - Retrieving stats for a table of multiple students\n-----" << endl;

    HashTable ht3;

    ht3.insert("MEDINA");
    ht3.insert("PARK");
    ht3.insert("HERNANDEZ");
    ht3.insert("JOHNSON");
    ht3.insert("MCMILLAN");
    ht3.insert("COOPER");
    cout << "Size of table: " << ht3.getSize() << endl;
    cout << "Number of inserts: " << ht3.getInsertCount() << endl;
    cout << "Number of collisions: " << ht3.getCollisionCount() << endl;
    cout << "Table after inserts: " << ht3.toString() << endl;
    cout << "Number of inserts / Number of collisions: " << (float)ht3.getInsertCount() / ht3.getCollisionCount() << endl;
    cout << "Size / Number of collisions: " << (float)ht3.getSize() / ht3.getCollisionCount() << endl;
    cout << endl;

    // Test 5: (SmartHashTable) - Double hashing a student to place them in a new table
    cout << "Test 5: (SmartHashTable) - Double hashing a student to place them in a new table\n-----" << endl;

    SmartHashTable smartHT(10);
    cout << "Inserting \"JOHNSON\"..." << endl;
    smartHT.insert("JOHNSON");
    cout << "Table after insert: " << smartHT.toString() << endl;
    cout << "Inserting \"HERNANDEZ\"..." << endl;
    smartHT.insert("HERNANDEZ");
    cout << "Number of collisions during insert: " << smartHT.getCollisionCount() << endl;
    cout << "Table after insert: " << smartHT.toString() << endl;
    cout << endl;

    // Test 6: (SmartHashTable) - Retrieving stats for a table of multiple students
    cout << "Test 6: (SmartHashTable) - Retrieving stats for a table of multiple students\n-----" << endl;

    SmartHashTable smartHT2;

    smartHT2.insert("MEDINA");
    smartHT2.insert("PARK");
    smartHT2.insert("HERNANDEZ");
    smartHT2.insert("JOHNSON");
    smartHT2.insert("MCMILLAN");
    smartHT2.insert("COOPER");
    cout << "Table after inserts: " << smartHT2.toString() << endl;
    cout << "Size of table: " << smartHT2.getSize() << endl;
    cout << "Number of inserts: " << smartHT2.getInsertCount() << endl;
    cout << "Number of collisions: " << smartHT2.getCollisionCount() << endl;
    cout << "Number of inserts / Number of collisions: " << (float)smartHT2.getInsertCount() / smartHT2.getCollisionCount() << endl;
    cout << "Size / Number of collisions: " << (float)smartHT2.getSize() / smartHT2.getCollisionCount() << endl;
    cout << endl;

    return 0;
}