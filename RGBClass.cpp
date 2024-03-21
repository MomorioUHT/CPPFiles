#include <iostream>
using namespace std;

class RGB{
private:
    int red;
    int green;
    int blue;
    string hexaColor;
public:
    RGB(int r, int g, int b){
        createColorFromInt(r,g,b);
    }

    RGB(string s) {
        createColorFromHex(s);
    }

    void changeColor(int r, int g, int b) {
        createColorFromInt(r, g, b);
    }

    void changeColor(string s) {
        createColorFromHex(s);
    }

    void changeColor(const RGB &inpRgb) {
        createColorFromInt(inpRgb.red, inpRgb.green, inpRgb.blue);
    }

    void createColorFromHex(string s) {
        string extracted_red, extracted_green, extracted_blue;

        if (hexaToInt(s.substr(1, 2)) > 255) {
            this->red = 255;
            extracted_red = "FF";
        } else {
            this->red = hexaToInt(s.substr(1, 2));
            extracted_red = s.substr(1, 2);            
        }

        if (hexaToInt(s.substr(3, 2)) > 255) {
            this->green = 255;
            extracted_green = "FF";
        } else {
            this->green = hexaToInt(s.substr(3, 2));
            extracted_green = s.substr(3, 2);            
        }

        if (hexaToInt(s.substr(5, 2)) > 255) {
            this->blue = 255;
            extracted_blue = "FF";
        } else {
            this->blue = hexaToInt(s.substr(5, 2));
            extracted_blue = s.substr(5, 2);            
        }

        this->hexaColor = '#' + extracted_red + extracted_green + extracted_blue;
    }

    void createColorFromInt(int r, int g, int b) {
        this->red = r;
        this->green = g;
        this->blue= b;

        if (r > 255) this->red = 255;
        if (g > 255) this->green = 255;
        if (b > 255) this->blue = 255;
        if (r < 0) this->red = 0;
        if (g < 0) this->green = 0;
        if (b < 0) this->blue = 0;

        this->hexaColor = '#' + intToHexa(red) + intToHexa(green) + intToHexa(blue);        
    }

    string intToHexa(int x) {
        string result;
	int startvalue = x;
        if (x == 0) return "00";

        while (x != 0) {
            int digit = x % 16;
            if (digit < 10) result = char('0' + digit) + result;
            else result = char('A' + digit - 10) + result;
            x /= 16;
        }
	if (startvalue <= 15) return '0' + result;
        return result;
    }

    int hexaToInt(string s) {
        int result = 0;
        for (char c : s) {
            result *= 16;
            if (isdigit(c)) result += c - '0';
            else result += toupper(c) - 'A' + 10;
        }
        return result;
    }

    int getRed() { return this->red; }
    int getGreen() { return this->green; }
    int getBlue() { return this->blue; }
    string toString() { return this->hexaColor; }
};

int main()
{
    // สร้าง object ของ class RGB เพื่อทดสอบเอง
}