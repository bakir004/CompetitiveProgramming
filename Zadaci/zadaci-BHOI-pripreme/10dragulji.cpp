#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers;
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
        sum += num;
    }
    int counter = 0;
    int minOdd = INT_FAST32_MAX;
    for (int i = 0; i < n; i++) {
        if(numbers[i] % 2 != 0) {
            counter++;
            minOdd = min(minOdd, numbers[i]);
        }
    }
    if(counter % 2 != 0) {
        cout << sum - minOdd;
    } else {
        cout << sum;
    }
    
    return 0;
}