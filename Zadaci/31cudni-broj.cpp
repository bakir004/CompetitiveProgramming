#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

string decToBin(int base, int num, int digits) {
    string converted = "";

    while(num > 0) {
        converted += to_string(num % base);
        num /= base;
    }
    while(converted.length() < digits) {
        converted += '0';
    }
    reverse(converted.begin(), converted.end());
    return converted;
}

string binToFinal(string num, vector<int> numSystem) {
    string final;
    for(int i = 0; i < num.length(); i++) {
        int index = num[i] - '0';
        final += to_string(numSystem[index]);
    }
    return final;
}

int main() {
    int n;
    cin >> n;

    vector<int> numSystem = {2, 3};
    int base = numSystem.size();

    // find how many digits n-th wierd number has
    int digits = 0;
    int i = 1;
    int lowerBound = 0;
    while(n > lowerBound) {
        lowerBound = pow(2, i) - 1;
        if(n == lowerBound) {
            digits++;
            break;
        } else if(n < lowerBound) {
            lowerBound = pow(2, i - 1) - 1;
            break;
        } else {
            digits++;
            i++;
        }
    }
    int numberForConversion = n - lowerBound;
    // convert to binary
    string res = decToBin(base, numberForConversion, digits);
    // convert to the final custom number system
    string final = binToFinal(res, numSystem);
    cout << final;
    return 0;
}