#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

typedef struct _point {
    double xPosition;
    double yPosition;
} point;

class Circle {
private:
    point center;
    double radius;
public:
    Circle(point inputCenter, double inputRadius) {
        center.xPosition = inputCenter.xPosition;
        center.yPosition = inputCenter.yPosition;
        radius = inputRadius;
    }
    double area() {
        return M_PI*pow(radius, 2);
    }
    double distanceFromCenter(point pt){
        return sqrt(pow((pt.xPosition - center.xPosition), 2) + pow((pt.yPosition - center.yPosition), 2));
    }
    double contains(point pt){
        double distance = sqrt(pow((pt.xPosition - center.xPosition), 2) + pow((pt.yPosition - center.yPosition), 2));
        if (distance <= radius) return 1;
        return 0;
    }
};

int main() {
    point inputCenter,dummyPoint;
    double inputRadius;
    cout << "Center of Circle: ";
    cin >> inputCenter.xPosition >> inputCenter.yPosition;
    cout << "Radius of Circle: ";
    cin >> inputRadius;

    Circle circle1(inputCenter, inputRadius);

    cout << "Point to Check: ";
    cin >> dummyPoint.xPosition >> dummyPoint.yPosition;
    cout << "Area of Circle is " << circle1.area() << endl;
    cout << "Distance from Center to Point " << "(" << dummyPoint.xPosition << ", " << dummyPoint.yPosition << ")" << " is " << circle1.distanceFromCenter(dummyPoint) << endl;
    if (circle1.contains(dummyPoint)) cout << "This circle contains this point.";
    else cout << "This point is not in this circle.";
}