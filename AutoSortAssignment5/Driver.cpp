#include <iostream>
#include "ArrayAutoSortList.h"

using std::cout;
using std::endl;

/*
* Parker Mayer
* CS 260
* 2/13/2023
*/

int main(int argc, char **argv){

    AutoSortList testList(5);

    /* Test 1: Inserting, searching for, and removing one element */

    cout << "---Test 1: Inserting, searching for, and removing one element---\n" << endl;
    cout << "Status of adding 14: " << testList.add(14) << endl;
    cout << "First instance of 14 at position: " << testList.peek(14) << endl;
    cout << "Status of removing 14: " << testList.remove(14) << endl;
    cout << "First instance of 14 at position: " << testList.peek(14) << endl;

    cout << endl;

    /* Test 2: Inserting, searching for, and removing multiple elements */

    cout << "---Test 2: Inserting, searching for, and removing multiple elements---\n" << endl;
    cout << "Status of adding 27: " << testList.add(27) << endl;
    cout << "Status of adding 9: " << testList.add(9) << endl;
    cout << "Status of adding 36: " << testList.add(36) << endl;

    cout << "First instance of 27 at position: " << testList.peek(27) << endl;
    cout << "First instance of 9 at position: " << testList.peek(9) << endl;
    cout << "First instance of 36 at position: " << testList.peek(36) << endl;

    cout << "Status of removing 9: " << testList.remove(9) << endl;
    cout << "First instance of 27 at position: " << testList.peek(27) << endl;
    cout << "Status of removing 27: " << testList.remove(27) << endl;
    cout << "First instance of 36 at position: " << testList.peek(36) << endl;
    cout << "Status of removing 36: " << testList.remove(36) << endl;

    cout << endl;

    /* Test 3: Removing from an empty array */
    
    cout << "---Test 3: Removing from an empty array---\n" << endl;
    cout << "Status of removing 7: " << testList.remove(7) << endl;

    cout << endl;

    /* Test 4: Overfilling a list */

    cout << "---Test 4: Overfilling a list---\n" << endl;
    for(int i = 0; i < 6; i++){
        cout << "Status of adding " << i << ": " << testList.add(i) << endl;
    }

    cout << endl;

    return 0;
}