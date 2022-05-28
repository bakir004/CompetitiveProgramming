#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int digits[10];
vector<int> number;
bool valid = true;

void incrementNumber(int step) {
    bool VALID = true;
    digits[number[number.size() - 1 - step]]--;
    number[number.size() - 1 - step]++;
    if(number[number.size() - 1 - step] == 10) {
        number[number.size() - 1 - step] = 0;
        digits[0]++;
        step++;
        if(step == number.size()) {
            reverse(number.begin(), number.end());
            number.push_back(1);
            reverse(number.begin(), number.end());
        } else {
            incrementNumber(step);
        }
    } else {
        digits[number[number.size() - 1 - step]]++;
    }
    for (auto i : digits) {
        if(i > 1) {
            VALID = false;
            break;
        }
    }
    
    valid = VALID;
}

int main() {
    int l, r;
    cin >> l >> r;

    int tempL = l;
    while(tempL >= 1) {
        int digit = tempL % 10;
        tempL /= 10;
        digits[digit]++;
        if(digits[digit] > 1) {
            valid = false;
        }
        number.push_back(digit);
    }

    reverse(number.begin(), number.end());

    int finalNumber = 0;
    for (auto i : digits) {
        if(i > 1) {
            valid = false;
            break;
        }
    }
    if(valid) {
        int factor = 1;
        for (int i = number.size() - 1; i >= 0; i--) {
            finalNumber += number[i] * factor;
            factor*=10;
        }
        cout << finalNumber;
        return 0;
    }
    for (int i = 0; i < r - l; i++) {
        incrementNumber(0);
        if(valid) {
            int factor = 1;
            for (int i = number.size() - 1; i >= 0; i--) {
                finalNumber += number[i] * factor;
                factor*=10;
            }
            break;
        }
        if(!valid && i == r - l - 1) {
            cout << -1;
            return 0;
        }
    }
    cout << finalNumber;
    



    return 0;
}