// STATUS: zavrsen
// IZVOR: KTOS-2016

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(int num){
    for (int i = 2; i < sqrt(num); i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

int stringToNum(string str) {
    int num = 0, counter = 0;
    for (int i = str.length() - 1; i >= 0; i--) {
        num += ((int)str[i] - '0') * pow(10, counter);
        counter++;
    }
    return num;
}

string decToOtherNumberSystem(int num, int base) {
    string convertedNumber = "";

    while(num >= 1) {
        convertedNumber += (num % base);
        num /= base;
    }

    reverse(convertedNumber.begin(), convertedNumber.end());

    return convertedNumber;
}

int solve(int num) {
    for (int i = 2; i < 10; i++) {
        int finalNumber = stringToNum(decToOtherNumberSystem(num, i));
        if(!isPrime(finalNumber)) {
            return -1;
        }
    }
    return num;
}

int main() {
    int t;
    vector<int> numbers = {51, 69, 99, 125, 129};

    // cin >> t;

    // for (int i = 0; i < t; i++)
    // {
    //     int num;
    //     cin >> num;
    //     numbers.push_back(num);
    // }
    
    for (int i = 0; i < numbers.size(); i++) {
        cout << solve(numbers[i]) << " ";
    }
}