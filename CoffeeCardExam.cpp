#include <iostream>
using namespace std;

class CoffeeCard{
private:
    double money;
    int points;
public:
    CoffeeCard() : money(0.0), points(0) {}

    void buyCoffee() {
        if (money >= 40 || points >= 3) {
            if (points >= 3) {
                points -= 3;
            } else {
                money -= 40;
                points++;
            }
        }
    }
    void addMoney(double x) {
        if (x > 0) {
            money += x;
        }
    }
    double getMoney() {
        return money;
    }
    int getPoints() {
        return points;
    }
};

int main(){
    CoffeeCard A = CoffeeCard();
    A.addMoney(200);
    A.buyCoffee();    
    A.buyCoffee();    
    A.buyCoffee();    
    A.buyCoffee();
    A.buyCoffee();
    cout << "Current Balance " << A.getMoney() << endl;   
    cout << "Current Point(s) " << A.getPoints() << endl;     
}