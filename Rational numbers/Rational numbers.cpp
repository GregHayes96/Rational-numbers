//This program is a rational numbers class implementation.
//Contains overload operators for addition, subtraction, multiplication, division & equals.


#include "Ration.h"

//main is testing some of the overload operators aswell as the getters, setters, constructors and copy constructor
int main() {
    try {
        Ration_numbers Fraction(1, 2);
        Ration_numbers Fraction_b(6, 22);
        Ration_numbers Fraction_c = Fraction;

        Fraction_c.get_number();    //should output 1/2
        Fraction.get_number();

        Fraction.set_number(13, 20);
        Fraction.get_number();

        std::cout << Fraction.conversion() << std::endl;

        //testing of all overload operators

        Fraction == Fraction_b;
        Fraction.get_number();

        Fraction + Fraction_b;
        Fraction.get_number();

        Fraction - Fraction_c;
        Fraction.get_number();

        Fraction * Fraction_b;
        Fraction.get_number();

        Fraction / Fraction_b;
        Fraction.get_number();
        
    }
    catch(const char* txtException){
        std::cerr << "Exception: " << txtException << std::endl;
    }
    catch (...) {
        std::cerr << "Exception: unknown exception" << std::endl;
    }
}

