#include <iostream>
#include <vector>
using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
    int left = 0, right = 0;
    int i,j, result;
    for (i=0; i<arr.size(); i++) {
        left += arr[i][i];
    }
    for (i=arr.size()-1, j=0; i>=0 && j<arr.size(); i--,j++) {
        right += arr[i][j];
    }
    result = left - right;
    if (result < 0) return -result;
    return result;
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n);

    for (int i = 0; i < n; ++i) {
        arr[i].resize(n);
        for (int j = 0; j < n; ++j) {
            int temp;
            cin >> temp;
            arr[i][j] = temp;
        }
    }

    int result = diagonalDifference(arr);
    cout << result << endl;
    return 0;
}