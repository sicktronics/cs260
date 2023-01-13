/*
* Parker Mayer
* CS260
* 1/11/23
*/

// #include is a preprocessor directive.
// use for including libraries (also consts).
#include <iostream> // input-output stream.

// explicit access to cout and endl tokens.
using std::cout;
using std::endl;

// main function
int main(void){
    cout << "Hello, World!" << endl;

    // explicitly returining zero (not necessary).
    // any non-zero value is false in C++.
    return 0;
}