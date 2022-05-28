// STATUS: zavrsen
// IZVOR: EJOI

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n = 6, k = 4;
    cin >> n >> k;

    int B = pow(2, n);
    int step = 2;
    vector<int> result;

    // za prvu iteraciju
    if(k == 1) {
        cout << 1;
        return 0;
    } else if(k == 2) {
        cout << B / 2 + 1;
        return 0;
    }
    result.push_back(1);
    result.push_back(B / 2 + 1);
    B /= 2;

    while(B >= 2) {
        int childrenInThisStep = pow(2, step - 1);
        for (int i = 0; i < childrenInThisStep / 2; i++) {
            int currentNum = B / 2 + 1 + i * B;
            result.push_back(currentNum);
            result.push_back(currentNum + pow(2, step - 2) * B);
        }
        B /= 2;
        step++;
    }
    cout << result[k - 1];

    return 0;
}
