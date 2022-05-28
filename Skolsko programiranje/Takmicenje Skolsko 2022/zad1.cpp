#include <iostream>

using namespace std;

void solve() {
    int n, sum = 0, currentDigit;
    cin >> n;
    if(n == 1) {
        cout << 1;
    } else if(n == 2) {
        cout << 2;
    } else if(n % 3 == 1) {
        currentDigit = 1;
        while(sum != n) {
            cout << currentDigit;
            sum += currentDigit;
            if(currentDigit == 2) {
                currentDigit = 1;
            } else {
                currentDigit = 2;
            }
        }
    } else {
        currentDigit = 2;
        while(sum != n) {
            cout << currentDigit;
            sum += currentDigit;
            if(currentDigit == 2) {
                currentDigit = 1;
            } else {
                currentDigit = 2;
            }
        }
    }
    cout << "\n";

    // 4 - 121
    // 5 - 212
    // 6 - 2121
    // 7 - 12121
    // 8 - 21212
    // 9 - 212121
    // 10- 1212121
    // 11- 2121212
    // 12- 21212121
}

int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    

    return 0;
}