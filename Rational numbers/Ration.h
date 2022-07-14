//Header file

#include <vector>
#include <iostream>
#include <cmath>
#include <string>

class Ration_numbers {
public:
    //constructor
    Ration_numbers(int num = 1, int denom = 1) : numerator(num), denominator(denom), whole(0), minus(false) {}
    //getters 
    std::string get_number();
    //setters
    int set_number(int num, int denum);
    //overload operators
    bool operator+(const Ration_numbers& rhs);
    bool operator-(const Ration_numbers& rhs);
    bool operator/(const Ration_numbers& rhs);
    bool operator*(const Ration_numbers& rhs);
    bool operator==(const Ration_numbers& rhs);
    double conversion()const;
    int euclidean();
    void above_one();
private:
    int numerator; //top
    int denominator; //bottom
    int whole;
    bool minus;

};