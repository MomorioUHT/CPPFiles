#include <iostream>
#include <string>
using namespace std;

class Hero {
private:
    string Name;
    int Level;
public:
    Hero(string inputName, int inputLevel) {
        Name = inputName;
        Level = inputLevel;
    }
    string getName() {
        return Name;
    }    
    int getLevel() {
        return Level;
    }
};

int main() {
    string TheName;
    int Number;
    cin >> TheName >> Number;
    Hero Hero1(TheName, Number);
    cout << Hero1.getName() << " " << Hero1.getLevel() << endl;
}