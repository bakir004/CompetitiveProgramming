// STATUS: zavrsen
// IZVOR: KTOS-2017

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isVarray(vector<int> arr) {
    int indexOfMinElement = min_element(arr.begin(), arr.end()) - arr.begin();
    for (int i = indexOfMinElement - 1; i > 0; i--) {
        if(arr[i - 1] <= arr[i]) {
            return false;
        }
    }
    for (int i = indexOfMinElement + 1; i < arr.size() - 1; i++) {
        if(arr[i] >= arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> arr;
    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        double num;
        cin >> num;
        arr.push_back(num);
    }

    if(isVarray(arr)) {
        cout << "DA";
    } else {
        cout << "NE";
    }
}