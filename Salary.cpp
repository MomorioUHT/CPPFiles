#include <iostream>
using namespace std;

int main() {
    char name[100],buffer[100];
    double n, salary, all = 0;

    cin >> name;
    cin >> salary;

    for (int i=0; i<12; i++) {
        cin >> n;
        all += (0.15*n) + salary;
    }

    sprintf(buffer, "%s %.2lf", name, all);
    cout << buffer;
}