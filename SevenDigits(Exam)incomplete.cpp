#include <iostream>
using namespace std;

class SevenSegmentDigit {
private:
    int digits_arr[7] = {};
public:
    SevenSegmentDigit() {
        for (int i=0; i<7; i++) {
            digits_arr[i] = 0;
        }
    }
    SevenSegmentDigit(int inpArray[]) {
        for (int i=0; i<7; i++) {
            digits_arr[i] = inpArray[i];
        }
    }
    void display() {
        for (int i=0; i<5; i++) {
            cout << display(i) << endl;
        }
    }
    string display(int line) {
        if (line == 0) {
            if (digits_arr[0] == 1) {
                return " -- ";
            } else {
                return "    ";
            }
        } else if (line == 1) {
            if (digits_arr[1] == 1 && digits_arr[2] == 1) {
                return "|  |";
            } else if (digits_arr[1] == 1) {
                return "|   ";
            } else if (digits_arr[2] == 1) {
                return "   |";
            } else {
                return "    ";
            }          
        } else if (line == 2) {
            if (digits_arr[3] == 1) {
                return " -- ";
            } else {
                return "    ";
            }
        } else if (line == 3) {
            if (digits_arr[4] == 1 && digits_arr[5] == 1) {
                return "|  |";
            } else if (digits_arr[4] == 1) {
                return "|   ";
            } else if (digits_arr[5] == 1) {
                return "   |";
            } else {
                return "    ";
            }                       
        } else if (line == 4) {
            if (digits_arr[6] == 1) {
                return " -- ";
            } else {
                return "    ";
            }
        } 
    }
};

int main() {
    int twoDigits[] = {1,0,1,1,1,0,1,0};
    SevenSegmentDigit two = SevenSegmentDigit(twoDigits);
    two.display();
}