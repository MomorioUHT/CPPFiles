#include <iostream>
#include <vector>
using namespace std;

vector<int> compareTriplets(vector<int> arrA, vector<int> arrB) {
    vector<int> resultArr(2);

    int a_score = 0;
    int b_score = 0;

    for (int i=0; i<arrA.size(); i++) {
        if (arrA[i] > arrB[i]) a_score++;
        else if (arrA[i] < arrB[i]) b_score++;
    }

    resultArr[0] = a_score;
    resultArr[1] = b_score;

    return resultArr;
}

int main() {
    int n = 3;
    vector<int> arrA(n), arrB(n);

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        arrA[i] = temp;
    }

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        arrB[i] = temp;
    }

    vector<int> result = compareTriplets(arrA, arrB);

    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
