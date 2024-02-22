#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void miniMaxSum(vector<int> arr, long *minSum, long &maxSum) {
    vector<long int> results(5);

    int avoid = 0;
    for (int i=0; i<5; i++) {
        long int temp = 0;
        for (int j=0; j<5; j++) {
            if (j != avoid) temp+= arr[j];
        }
        results[i] = temp;
        avoid++;
    }

    long int max = results[0];
    long int min = results[0];

    for (int i = 0; i < 5; i++) {
        if (results[i] > max) max = results[i];
        if (results[i] < min) min = results[i];
    }

    *minSum = min;
    maxSum = max;
}

int main() {
    int n = 5;
    long min, max;
    vector<int> ar;

    for (int i = 0; i < n; ++i) {
        long temp;
        cin >> temp;
        ar.push_back(temp);
    }

    miniMaxSum(ar, &min, max);
    cout << min << " " << max << endl;
    return 0;
}