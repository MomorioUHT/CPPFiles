#include <iostream>
using namespace std;

class Competitor {
private:
    int score_arr[10] = {};
    int totalScore;
public:
    Competitor() {
        for (int i=0; i<10; i++) {
            score_arr[i] = 0;
            totalScore = 0;
        }
    }
    int input() {
        int x;
        for (int i=0; i<10; i++) {
            cin >> x;
            score_arr[i] = x;
            totalScore += x;
        }        
    }
    int calculateTotalScore() {
        return totalScore; //Lol
    }
    int isMoreThan(Competitor *others) {
        int temp = 0;
        for (int i=0; i<10; i++) {
            if (score_arr[i] > others->score_arr[i]) {
                temp++;
            }
        }
        return temp;
    }
};

int main() {
    Competitor Sample = Competitor();
    Sample.input();

    int amount;
    cin >> amount;

    Competitor student_arr[amount];
    for (int i=0; i<amount; i++) {
        student_arr[i] = Competitor();
        student_arr[i].input();
    }

    cout << Sample.calculateTotalScore() << endl;
    for (int i=0; i<amount; i++) {
        cout << student_arr[i].calculateTotalScore() << " " << 
        student_arr[i].isMoreThan(&Sample) << endl;
    }
}