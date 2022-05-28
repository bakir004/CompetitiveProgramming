#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int maxElement = -1, sum = 0;
    int numOfStands;
    cin >> numOfStands;

    for (int i = 0; i < numOfStands; i++) {
        int num;
        cin >> num;
        sum += num;
        num > maxElement ? maxElement = num : maxElement;
    }
    sum -= maxElement;
    int res;
    if(maxElement > sum) {
        res = 2 * maxElement;
    } else {
        res = sum + maxElement;
    }
    cout << res;

    return 0;
}