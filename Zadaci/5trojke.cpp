// STATUS: zavrsen
// IZVOR: KTOS-2016

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // vector<int> numbers = {2,4,8,16,33,66,132};
    vector<int> numbers;

    while(true) {
        int num;
        cin >> num;
        if(num != 0) {
            numbers.push_back(num);
        } else {
            break;
        }
    }

    int counter = 0;
    for (int i = 1; i < numbers.size() - 2; i++) {
        if(numbers[i - 1] == numbers[i] / 2 && numbers[i + 1] == numbers[i] * 2) {
            counter++;
        }
    }
    
    cout << counter;
}