#include <iostream>
using namespace std;

class Animal
{
private:
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
int main()
{
}