// STATUS: nezavrsen
// IZVOR: BHOI

#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>

using namespace std;

bool checkIfEqualDeque(deque<int> arr1, deque<int> arr2) {
    for (int i = 0; i < arr1.size(); i++) {
        if(arr1[i] != arr2[i])
            return false;
    }
    return true;
}

bool doesContainSameElements(set<int> arr1, set<int> arr2) {
    return arr1 == arr2;
}

set<int> toSet(vector<int> arr) {
    set<int> newSet;
    for (int i = 0; i < arr.size(); i++) {
        newSet.insert(arr[i]);
    }
    return newSet;
}

deque<int> toDeque(vector<int> arr) {
    deque<int> newDeque;
    for (int i = 0; i < arr.size(); i++) {
        newDeque.push_back(arr[i]);
    }
    return newDeque;
}

vector<int> toVector(deque<int> arr) {
    vector<int> newVector;
    for (int i = 0; i < arr.size(); i++) {
        newVector.push_back(arr.front());
        arr.pop_front();
    }
    return newVector;
}

int main() {

    int numOfElements = 6;
    deque<int> originArray = {1,4,2,2,4,3};
    deque<int> array = {2,2,4,3,1,4};

    // int numOfElements;
    // vector<int> originArray;
    // vector<int> array;

    // cin >> numOfElements;

    // for (int i = 0; i < numOfElements; i++) {
    //     int num;
    //     cin >> num;
    //     originArray.push_back(num);
    // }
    // for (int i = 0; i < numOfElements; i++) {
    //     int num;
    //     cin >> num;
    //     array.push_back(num);
    // }

    if(checkIfEqualDeque(originArray, array)) {
        cout << "DA\n0";
        return 0;
    }
    deque<int> dek = array;
    for (int i = 1; i < originArray.size(); i++) {
        vector<int> tempVector;
        deque<int> tempArray = array;
        for (int i = array.size() - 1; i > array.size() - 1 - i; i--) {
            tempVector.push_back(tempArray[i]);
            tempArray.pop_back();
        }
        reverse(tempVector.begin(), tempVector.end());
        // deque
        
        if(checkIfEqualDeque(originArray, dek)) {
            cout << "DA\n" << i;
            return 0;
        }
    }
    cout << "NE";
    return 0;
}