#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Shape3D
{
public:
    virtual double volumn() const = 0;
    virtual double surfaceArea() const  = 0;
};

class RightRectangularPyramid: public Shape3D {
private:
    double width;
    double length;
    double height;
public:
    RightRectangularPyramid(double w = 0.0, double l = 0.0, double h = 0.0) : 
    width(w), length(l), height(h) {}

    double volumn() const override {
        return (1.0 / 3.0) * width * length * height;
    }
    double surfaceArea() const override {
        return (width * length) + (0.5 * width * sqrt(4 * pow(height, 2) + 
               pow(length, 2))) + (0.5 * length * sqrt(4 * pow(height, 2) + 
               pow(width, 2)));
    }
};

class Sphere: public Shape3D {
private:
    double radius;
public:
    Sphere(double r = 0.0) : radius(r) {}

    double volumn() const override {
        return (4.0 / 3.0) * M_PI * pow(radius, 3);
    }
    double surfaceArea() const override {
        return 4.0 * M_PI * pow(radius, 2);
    }
};

int main()
{
	int tc;
	cin >> tc;
	if (tc == 1) {
		Shape3D **shapes = new Shape3D*[3];
		shapes[0] = new RightRectangularPyramid(1, 5.2, 7);
		shapes[1] = new Sphere(10.6);
		shapes[2] = new RightRectangularPyramid(3, 3.5, 4.13);
		for (int i = 0; i < 3; i++) {
			cout << "Volumn: " << (*shapes)->volumn() << endl;
			cout << "Surface Area: " << (*shapes)->surfaceArea() << endl;
			cout << "--------------------\n";
			*shapes++;
		}
	} else if (tc == 2) {
		RightRectangularPyramid rectangle;
		Sphere sphere;
		cout << rectangle.volumn() << endl;
		cout << rectangle.surfaceArea() << endl;
		cout << sphere.volumn() << endl;
		cout << sphere.surfaceArea() << endl;
	} else if (tc == 3) {
		RightRectangularPyramid rectangle(171.5, 45.33, 31.02);
		cout << rectangle.volumn() << endl;
		cout << rectangle.surfaceArea() << endl;
	} else if (tc == 4) {
		Sphere sphere(34.25);
		cout << sphere.volumn() << endl;
		cout << sphere.surfaceArea() << endl;
	} else if (tc == 5) {
		RightRectangularPyramid rectangle(171.5, 45.33, 31.02);
		Sphere sphere(34.25);
		Shape3D *shape = &rectangle;
		cout << shape->volumn() << " " << shape->surfaceArea() << endl;
		shape = &sphere;
		cout << shape->volumn() << " " << shape->surfaceArea() << endl;
	} else if(tc == 6) {
	}

}