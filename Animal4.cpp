#include <iostream>
using namespace std;

class Animal
{
protected:
    int happiness;
    int energy;
    int fullness;
    const int MAX_HAPPINESS = 100;
    const int MAX_ENERGY = 100;
    const int MAX_FULLNESS = 100;
    void limitStat();
public:
    Animal(int, int, int);
    int getHappiness();
    int getEnergy();
    int getFullness();
    void eat(int);
    void play(int);
    void sleep(int);
};

class Bird: public Animal
{
public:
    Bird(int, int, int);
    void fly(int);
    void sing();
};

class Pet
{
protected:
    string name;
public:
    Pet(string);
    string getName();
    void setName(string);
};

class OwnedBird: public Bird, public Pet
{
public:
    OwnedBird(string, int, int, int);
};
//=========================================

Animal::Animal(int a, int b, int c) {
    this->happiness = a;
    this->energy = b;
    this->fullness = c;
    limitStat();
}
void Animal::limitStat() {
    if (happiness > MAX_HAPPINESS) this->happiness = MAX_HAPPINESS;
    if (energy > MAX_ENERGY) this->energy = MAX_ENERGY;
    if (fullness > MAX_FULLNESS) this->fullness = MAX_FULLNESS;
    if (happiness < 0) this->happiness = 0;
    if (energy < 0) this->energy = 0;
    if (fullness < 0) this->fullness = 0;
}
void Animal::eat(int x) {
    if (x <= 0) return;
    this->fullness += x;
    if (fullness > 100) this->happiness -= 10;
    limitStat();
}
void Animal::play(int hour) {
    if (hour <= 0) return;
    for (int i = 0; i < hour; i++) {
        if (energy <= 0 && fullness <= 0) break;
        this->energy -= 10;
        this->fullness -= 20;
        this->happiness += 5;        
    }
    limitStat();
}
void Animal::sleep(int hour) {
    if (hour <= 0) return;
    this->energy += 10 * hour;
    this->fullness -= 10 * hour;
    limitStat();
}
int Animal::getHappiness() {
    return happiness;
}
int Animal::getEnergy() {
    return energy;
}
int Animal::getFullness() {
    return fullness;
}
//=========================================
Bird::Bird(int a, int b, int c) : Animal(a,b,c) {}

void Bird::fly(int hour) {
    if (hour <= 0) return;
    this->energy -= 5 * hour;
    limitStat();
}

void Bird::sing() {
    this->happiness += 5;
    limitStat();
}
//=========================================
Pet::Pet(string inpName) : name(inpName) {}

string Pet::getName() {
    return this->name;
}
void Pet::setName(string x) {
    this->name = x;
}
//=========================================
OwnedBird::OwnedBird(string inpName, int a, int b, int c) : Bird(a, b, c), Pet(inpName) { }
//========================================

//=========================================

int main()
{
    char action;
    int hour;
    int happiness, energy, fullness;
    cin >> happiness >> energy >> fullness;
    OwnedBird animal("Dobby", happiness, energy, fullness);
    while (1) {
        cin >> action;
        if (action == 'q') break;
        cin >> hour;
        switch (action) {
            case 'e':
                animal.eat(hour);
                break;
            case 'p':
                animal.play(hour);
                break;
            case 's':
                animal.sleep(hour);
                break;
            case 'f':
                animal.fly(hour);
                break;
            case 'i':
                for (int i = 0; i < hour; i++)
                    animal.sing();
                break;
            case 'n':
                if (hour < 5)
                    animal.setName("Debby");
                else
                    animal.setName("Shogun");
                break;
        }
    }
}