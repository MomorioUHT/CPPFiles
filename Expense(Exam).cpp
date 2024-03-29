#include <iostream>
using namespace std;

class Expense {
protected:
    int day,month,year;
    double amount;
public:
    Expense(int, int, int, double);
    virtual double dailyExpense(int, int, int);
    virtual double monthlyExpense(int, int);
};

Expense::Expense(int d, int m, int y, double amt) {
    this->day = d;
    this->month = m;
    this->year = y;
    this->amount = amt;
}
double Expense::dailyExpense(int d, int m, int y) {
    if (d != day || m != month || y != year) {
        return 0;
    }
    return amount;
}   
double Expense::monthlyExpense(int m, int y) {
    if (m != month || y != year) {
        return 0;
    }
    return amount;
}  

int main() {
    Expense breakfast = Expense(1, 2, 2024, 45);
    Expense *lunch = new Expense(2, 2 ,2024, 120);
    cout << breakfast.dailyExpense(1, 2, 2024) << endl;
    cout << lunch->dailyExpense(2, 2, 2024) << endl;
    cout << lunch->monthlyExpense(2, 2024) << endl;
}