#include <iostream>
using namespace std;

class Transportation
{
public:
    virtual double fare() = 0;
};

class Taxi: public Transportation {
private:    
    double distance;
public:
    double setDistance(double x) {
        distance = x;
    }
    double fare() {
        return 35 + (2*distance);
    }
};

class BmtaBus: public Transportation {  
public:
    double fare() {
        return 6.50;
    }
};

class BTS: public Transportation
{
private:
    int stations = 0;
public:
    void setStation(int x) {
        stations = x;
    }
    double fare() {
        return 15 + (5 * stations);
    }
};

class Passenger
{
private:
    double totalFare = 0;
public:
    void addTransportation(Transportation &vehicle) {
        totalFare += vehicle.fare();
    }
    double getTotalFare() {
        return totalFare;
    }
};


int main()
{
    Passenger passenger;
    while(1) {
        char transportType;
        cin >> transportType;
        if (transportType == 'A') {
            Taxi *taxi = new Taxi();
            double distance;
            cin >> distance;
            taxi->setDistance(distance);
            passenger.addTransportation(*taxi);
        } else if (transportType == 'B') {
            BmtaBus *bus = new BmtaBus();
            passenger.addTransportation(*bus);

        } else if (transportType == 'C') {
            BTS *bts = new BTS();
            int station;
            cin >> station;
            bts->setStation(station);
            passenger.addTransportation(*bts);

        } else {
            break;
        }
    }
    cout << "Total Fare: " << passenger.getTotalFare() << endl;
}