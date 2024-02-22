#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int birthdayCakeCandles(vector<int> candles) {
    int count = 0;
    std::sort(candles.begin(), candles.end());

    for (int i=candles.size()-1; i>=0; i--) {
        if (candles[i] < candles[candles.size()-1]) break;
        count++;
    }

    return count;
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

    int result = birthdayCakeCandles(ar);
    cout << result << endl;
    return 0;
}