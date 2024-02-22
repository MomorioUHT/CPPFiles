#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, temp, max=0, find=0;
    cin >> n;
    int arr[n];
    vector<int> odd,even;

    //Validate
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr[i] = temp;
    }
    //findmax
    for (int i = 0; i < n; i++) {
       if (arr[i] >= max) max = arr[i];
    }

    //Create Array till max elements
    int all[max];
    for (int i=0; i<max; i++) all[i] = i+1;

    for (int i=0; i<max; i++) {
        //Check if all[i] is in arr[i] for not
        int found = 0;
        for (int j=0; j<n; j++) {
            if (all[i] == arr[j]) {
                found = 1;
                break;
            }   
        }
        if (found == 0) {
            if (all[i] % 2 == 1) odd.push_back(all[i]);
            else even.push_back(all[i]);
        }
        found = 0;
    }
    for (int i=0; i<odd.size(); i++) {
        cout << odd[i] << " ";
    }
    cout << endl;
    for (int i=0; i<even.size(); i++) {
        cout << even[i] << " ";
    }
}
