#include <iostream>
using namespace std;

class Transportation
{
public:
    virtual double fare() = 0;
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

int main()
{
    int tc;
    cin >> tc;
    if (tc == 1) {
        int station;
        cin >> station;
        BTS bts;
        bts.setStation(station);
        cout << "BTS fare: "
             << bts.fare() << endl;
    } else if(tc == 2) {
        int station;
        cin >> station;
        BTS bts;
        bts.setStation(station);
        Transportation *transport = &bts;
        cout << "Transporataion fare: "
             << transport->fare() << endl;
    }
}