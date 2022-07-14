#include "Ration.h"

//getter to return number
std::string Ration_numbers::get_number() {
    //this adds both numerator and denominator into one string which can be returned
    std::string temp_num = std::to_string(numerator);
    temp_num += "/";
    std::string temp_den = std::to_string(denominator);
    temp_num += temp_den;
    if (numerator == denominator) {
        whole++;
        std::cout << whole << std::endl;
        return temp_num;
    }
    if (whole > 0 && minus == false) {
        std::cout << whole << " " << temp_num << std::endl;
        return temp_num;
    }
    else if (whole > 0 && minus == true) {
        std::cout << "-" << whole << " " << temp_num << std::endl;
        return temp_num;
    }
    else {
        std::cout << temp_num << std::endl;
        return temp_num;
    }
}

// if the fraction is top heavy, this will add
void Ration_numbers::above_one() {
    while (numerator > denominator) {
        numerator -= denominator;
        whole++;
    }
}

//sets the numbers
int Ration_numbers::set_number(int num, int denom) {
    //pre-condition : cant be a top heavy fraction
    if (num > denom) throw "Fraction top heavy";
    this->numerator = num;
    this->denominator = denom;
    return 0;
}

//takes the rational number and makes it into a decimal number
double Ration_numbers::conversion() const {
    double num = numerator;
    double den = denominator;
    double conv = num / den;
    return conv;
}

//-------------------------------------------------------------------------
//overload operators

bool Ration_numbers::operator+(const Ration_numbers& rhs) {
    numerator = (this->numerator * rhs.denominator) + (rhs.numerator * this->denominator);
    denominator = this->denominator * rhs.denominator;
    euclidean();
    return true;
}

bool Ration_numbers::operator-(const Ration_numbers& rhs) {
    //still need to implement a way to handle it becoming a negative fraction
    numerator = (this->numerator * rhs.denominator) - (rhs.numerator * this->denominator);
    denominator = this->denominator * rhs.denominator;
    euclidean();
    return true;
}
bool Ration_numbers::operator/(const Ration_numbers& rhs) {
    numerator *= rhs.denominator;
    denominator = rhs.numerator * denominator;
    euclidean();
    return true;
}

bool Ration_numbers::operator*(const Ration_numbers& rhs) {
    numerator *= rhs.numerator;
    denominator *= rhs.denominator;
    euclidean();
    return true;
}

bool Ration_numbers::operator==(const Ration_numbers& rhs) {
    if (this->numerator == rhs.numerator && denominator == rhs.denominator) {
        std::cout << "is Equal" << std::endl;
        return true;
    }
    else
        std::cout << "not Equal" << std::endl;
    return false;
}

//-------------------------------------------------------------------------
//algorithm for finding the GCD (greatest common devisor) of two fractions.
//once simplified, it applies the changes to the class object.

int Ration_numbers::euclidean() {
    //first check to see if the number is a top heavy fraction. adds the number to one if it is.
    above_one();
    //divisible by itself clause
    if (this->denominator % this->numerator == 0) {
        set_number((this->numerator / this->numerator), (denominator / numerator));
        return 0;
    }
    //the algorithm
    // Changed Q to i to fit with the FOR loop
    // A = B * i + R
    int a{ denominator };
    int b{ numerator };
    int r{ b };  //remainder
    bool skip{ false };
    for (int i = 0; ++i;) {
        int larger = b * i;
        if (a == 0) {
            set_number((numerator / b), (denominator / b));
            return 0;
        }
        else if (b == 0) {
            set_number((numerator / a), (denominator / a));
            return 0;
        }
        else if (larger > a) {
            // int temp = r;
            r = a - (larger - b);
            a = b;
            b = r;
            i = 1;
        }
    }
}