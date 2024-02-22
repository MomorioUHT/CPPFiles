#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdio>
using namespace std;

void signedRatio(vector<int> arr) {
    int allSize = arr.size();
    int minus = 0, zero = 0, plus = 0;
    int i;
    for (i=0; i<allSize; i++) {
        if (arr[i] < 0) minus++;
        else if (arr[i] > 0) plus++;
        else if (arr[i] == 0) zero++;
    }

    double signedPlus = (double)plus/allSize;
    double signedMinus = (double)minus/allSize;
    double signedZero = (double)zero/allSize;

    cout << fixed << setprecision(6);
    cout << signedPlus << endl;
    cout << signedMinus << endl;
    cout << signedZero << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        ar[i] = temp;
    }

    signedRatio(ar);
    return 0;
}