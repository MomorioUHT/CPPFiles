#include <iostream>
using namespace std;

#include <sstream>
#include <cmath>
#include <iomanip>

class Complex {
private:
    double real;
    double img;
public:
    Complex(double x, double y) { real = x; img = y; }
    Complex(double x) { real = x; img = 0; }
    Complex() { real = 0; img = 0; }
    string toString() const {
        stringstream ss;
        if (real == 0 && img == 0) {
            return "0";
        } 
        else if (real == 0 && img != 0) {
            if (img == 1) ss << "i";
            else if (img == -1) ss << "-i";
            else {
                if (img != floor(img)) ss << fixed << setprecision(6) << img << "i";
                else ss << fixed << setprecision(0) << img << "i";
            }
        }
        else if (real != 0 && img == 0) {
            if (real != floor(real)) ss << fixed << setprecision(6) << real;
            else ss << fixed << setprecision(0) << real;         
        }
        else if (real != 0 && img != 0) {
            if (real != floor(real)) ss << fixed << setprecision(6) << real;
            else ss << fixed << setprecision(0) << real;
            
            if (img > 0) ss << "+";

            if (img == 1) ss << "i";
            else if (img == -1) ss << "-i";
            else {
                if (img != floor(img)) ss << fixed << setprecision(6) << img << "i";
                else ss << fixed << setprecision(0) << img << "i";
            }  
        }
        return ss.str();
    }
    Complex operator +(Complex other) {
        Complex temp;
        temp.real = real + other.real;
        temp.img = img + other.img;
        return temp;
    }
    Complex operator -(Complex other) {
        Complex temp;
        temp.real = real - other.real;
        temp.img = img - other.img;
        return temp;
    }
    friend ostream& operator<<(ostream& os, const Complex& other);
};
ostream& operator<<(ostream& os, const Complex& other) {
    os << other.toString(); 
    return os;
}

int main()
{
    // เขียน object เพื่อทดสอบเอง
}