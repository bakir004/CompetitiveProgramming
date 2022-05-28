#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    vector<int> cities;
    int n;
    cin >> n;

    int adder = 0;
    int totalCost = 0;
    int lastNum;
    int currentCost;

    int num;
    cin >> num;
    currentCost = num;
    totalCost += currentCost;
    for (int i = 1; i < n; i++) {
        cin >> num;
        if(num < currentCost + 1) {
            currentCost = num;
        } else {
            currentCost++;
        }
        totalCost += currentCost;
    }
    cout << totalCost;

    return 0;
}
