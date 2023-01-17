/*
* Parker Mayer
* CS260
* 1/16/23
* See README for list of resources I used to make this file.
*/

// The Marble class
class Marble{

    public: 
        // Class members (properties of marbles).
        int idNum;
        double diameter;
        double mass;
        char color;
        // The constructor for a marble with properties:
        // ID number, Diameter (mm), mass (g), color ('r' = red, 'g' = green, 'b' = blue).
        Marble (int id, double d, double m, char c) {

            idNum = id;
            diameter = d;
            mass = m;
            color = c;
        }

        // This is an overloaded "==" operator that compares two Marble objects via their ID numbers.
        // We will use this in the removeMarble method to check if we've found the marble we want to remove.
        bool operator==(const Marble &rhs){
            return this->idNum == rhs.idNum;
        }
}; // End of Marble class.
