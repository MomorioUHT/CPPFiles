#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;
public:
    Time(int hour, int minute, int second) {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    Time(int duration) {
        hour = duration/3600;
        duration -= (hour*3600);
        minute = duration/60;
        duration -= (minute*60);
        second = duration;
    }
    Time(){
        hour = 0;
        minute = 0;
        second = 0;
    }

    int getDuration() {
        return (hour*3600) + (minute*60) + second;
    }

    Time add(Time other) {
        Time yourTime;

        int newDuration = this->getDuration() + other.getDuration();
        if (newDuration >= 86400) yourTime = Time(newDuration%86400);
        else yourTime = Time(newDuration);
        return yourTime;
    }

    int subtract(Time other) {
        int myDuration = (hour*3600) + (minute*60) + second;
        int otherDuration = (other.hour*3600) + (other.minute*60) + other.second;
        if (myDuration > otherDuration) return myDuration - otherDuration;
        return 86400 - (otherDuration - myDuration);
    }   

    int equals(Time other) {
        return (this->hour == other.hour) && (this->minute == other.minute) && (this->second == other.second);
    }

    string toString() const {
        return to_string(hour / 10) + to_string(hour % 10) + ":" +
                to_string(minute / 10) + to_string(minute % 10) + ":" +
                to_string(second / 10) + to_string(second % 10);
    }

    int getHour() {
        return hour;
    }
    int getMinute() {
        return minute;
    }
    int getSecond() {
        return second;
    }
};


int main()
{
    // //Test Time Validation using H M S
    // int H,M,S;
    // cin >> H >> M >> S;
    // Time SimpleTime(H,M,S);
    // cout << SimpleTime.getH() << ":" << SimpleTime.getM() << ":" << SimpleTime.getS() << endl;

    // //Test Time Validation using Durations
    // int DU;
    // cin >> DU;
    // Time SimpleTime(DU);
    // cout << SimpleTime.getH() << ":" << SimpleTime.getM() << ":" << SimpleTime.getS() << endl;

    // //Test Subtract Time
    // Time timeA(2,2,2);
    // Time timeB(1,1,1);

    // cout << "a-b is " << timeA.subtract(timeB) << endl;
    // cout << "b-a is " << timeB.subtract(timeA) << endl;

    // //Test Add Time
    // Time timeC(23,59,30);
    // Time timeD(2,0,35);
    // cout << "a+b is " << timeC.add(timeD).getH() << ":" << timeC.add(timeD).getM() << ":" << timeC.add(timeD).getS() << endl;

    //Test getString
    // Time timeE(20,4,51);
    // cout << timeE.toString() << endl;

}