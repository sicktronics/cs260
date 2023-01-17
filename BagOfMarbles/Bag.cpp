/*
* Parker Mayer
* CS260
* 1/16/23
* See README for list of resources I used to make this file.
*/

// This file acts as the "driver file" for testing the program.

// Including the input-output and vector libraries.
#include <iostream>
#include <vector>
// Including our Marble class
#include "Marble.cpp"

using namespace std;

// Declaring our "bag" vector to store marbles.
vector<Marble> bag;

// Our method for adding a marble to our bag array
void addMarble(Marble m){
    // This adds a marble to the bag by adding a new element
    // in at the end of our vector.
    bag.push_back(m);
} // End of addMarble method.

// Our method for removing a marble from our bag array.
void removeMarble(Marble m){
    // This iterator will let us point to a specific spot
    // in our bag vector.
    vector<Marble>::iterator toRmv;

    for(int i=0;i<bag.size();i++){    // For every marble in the bag...
        if(bag[i]==m){                  // ...if a given marble has the same id as
                                        // the one we passed in...
            toRmv = bag.begin()+i;      // ...set the iterator to the current location
                                        // in the bag and...
            bag.erase(toRmv);           // ...delete it from the vector!
        }
    }
} // End of removeMarble method.

// Running a few tests.
int main(void){

    // TEST 1: Adding and removing a single marble.
    cout << "TEST 1: Adding and removing a single marble." << endl;
    Marble m1(1, 2.3, 4.2, 'b');

    addMarble(m1);

    cout << "Number of marbles: " << bag.size() << endl;
    for(int i = 0;i<bag.size();i++){
        cout << "Marble ID# " << bag[i].idNum << endl;
    }
    cout << "- - - - -" << endl;
    
    removeMarble(m1);

    cout << "Number of marbles: " << bag.size() << endl;
    cout << "- - - - -" << endl;

    // TEST 2: Adding and removing a few marbles.
    cout << "TEST 2: Adding and removing a few marbles." << endl;
    Marble m2(2, 2.7, 4.1, 'g');
    Marble m3(3, 3.1, 5.6, 'r');
    Marble m4(4, 3.7, 4.6, 'r');

    addMarble(m2);
    addMarble(m3);
    addMarble(m4);

    cout << "Number of marbles: " << bag.size() << endl;
    for(int i = 0;i<bag.size();i++){
        cout << "Marble ID# " << bag[i].idNum << endl;
    }
    cout << "- - - - -" << endl;

    removeMarble(m2);
    removeMarble(m4);

    cout << "Number of marbles: " << bag.size() << endl;
    for(int i = 0;i<bag.size();i++){
        cout << "Marble ID# " << bag[i].idNum << endl;
    }
    cout << "- - - - -" << endl;

    // TEST 3: Pulling a marble out of an empty bag.
    cout << "TEST 3: Pulling a marble out of an empty bag." << endl;
    removeMarble(m3); // Starting by emptying the bag
    cout << "Number of marbles: " << bag.size() << endl;
    removeMarble(m4);
    cout << "Number of marbles: " << bag.size() << endl;
    // Note: this does not throw an error because
    //       removing happens only if the marble is
    //       in the bag to begin with (see removeMarble above).

} // End of main.