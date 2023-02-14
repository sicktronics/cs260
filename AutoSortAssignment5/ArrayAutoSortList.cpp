#include <iostream>
#include "ArrayAutoSortList.h"

using std::cout;
using std::endl;

/*
* Parker Mayer
* CS 260
* 2/13/2023
*
* NOTE: This file is a modification of the array arbitrary
*       list created in class.
*/


// The constructor
AutoSortList::AutoSortList(int initialSize){

   // Initializing a new int array 
   internalStorage = new int[initialSize];

   // Filling it with zeroes 
   for(int i = 0; i < initialSize; i++){
    internalStorage[i]=0;
   }
   // Setting up the end of list marker and a variable to track size internally
   endOfList = 0;
   size = initialSize;
}

// The add method uses bubble sort to sort incoming values
bool AutoSortList::add(int value){

    // If we try to overfill, terminate the process
    if(endOfList >= size){
        return false;
    }

    // 1. Append the new element
    internalStorage[endOfList] = value;

    // 2. Re-sort using bubble sort
    // Iterate across the current list of elements
    for (int i = 0; i < endOfList; i++){

        // Iterating over the unsorted elements (i elements are in place at a given time)
        for (int j = 0; j < endOfList - i; j++){

            // If the value at "j" is greater than the value at "j+1"
            if (internalStorage[j] > internalStorage[j + 1]){

                // Swap them!
                int temp = internalStorage[j+1];
                internalStorage[j+1] = internalStorage[j];
                internalStorage[j] = temp;
            }
        }
    }
    
    endOfList++; // Update the end of list marker
    return true;
}

// The remove method uses binary search to find and remove a given value
bool AutoSortList::remove(int value){

    int low = 0; 
    int high = endOfList;
    int temp = 0;

    while(low <= high){

        // Set our midpoint to be in the middle of the low and high bounds
        int mid = (low+high)/2;

        // If we find the value
        if(value == internalStorage[mid]){ // what to do if we find the value

            // Store it and shift everything over to fill the gap
            // (Storing it is not necessary in this case)
            temp = internalStorage[mid];

            for(int i = mid; i <= endOfList; i++){
                internalStorage[i] = internalStorage[i+1];
            }

            endOfList--; // Update the end of list marker
            return true;

        } else if (value > internalStorage[mid]){ 
            // We need to search right of the current mid point. 
            low = mid + 1;
        } else { 
            // We need to search left of the current mid point.                                    
            high = mid - 1;
        }
    }

    return false;
}


// The peek method searches for and returns the position of the 
// first instance of a given value
int AutoSortList::peek(int value){

    // Same binary search procedure as for remove method
    int low = 0; 
    int high = endOfList;
    int pos = -1;

    while(low <= high){
        
        int mid = (low+high)/2;

        // Return the position if we find the value
        if(value == internalStorage[mid]){
            return mid;    

        } else if (value > internalStorage[mid]){ 
            // We need to search right of the current mid point. 
            low = mid + 1;

        } else { 
            // We need to search left of the current mid point.                                    
            high = mid - 1;
        }
    }

    return pos;
}