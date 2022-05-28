#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> rotateArray(vector<int> arr, int d, string direction) {
    if(arr.size() == 0) {
        return {};
    }
    if(arr.size() == 1) {
        return {arr[0]};
    }
    vector<int> rotatedArr(arr.size(), 0);
    d = d % arr.size();
    int length = arr.size();
    if(direction == "LIJEVO") {
        d *= -1;
    }

    for (int i = 0; i < arr.size(); i++) {
        int wantedIndex = i + d;
        if(wantedIndex >= length) {
            wantedIndex -= length;
        }
        if(wantedIndex < 0) {
            wantedIndex += length;
        }
        rotatedArr[wantedIndex] = arr[i];
    }
    return rotatedArr;
}

int main() {
    int n, d;
    string direction;
    vector<int> arr;

    // int n = 5, d = 4;
    // string direction = "LIJEVO";
    // vector<int> arr = {1,2,3,4,5};

    fstream fileIn;
    fstream fileOut;

    fileIn.open("input.txt", ios::in);
    if(!fileIn.is_open()) {
        cout << "File Error";
    }

    fileIn >> n >> d;
    fileIn >> direction;

    for (int i = 0; i < n; i++) {
        int element;
        fileIn >> element;
        arr.push_back(element);
    }
    fileIn.close();

    fileOut.open("output.txt", ios::out | ios::trunc);

    vector<int> rotatedArray = rotateArray(arr, d, direction);

    for (int i = 0; i < rotatedArray.size(); i++) {
        cout << rotatedArray[i] << " ";
        fileOut << rotatedArray[i] << " ";
    }

    fileOut.close();

    return 0;
}