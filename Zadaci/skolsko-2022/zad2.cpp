#include <iostream>

using namespace std;

int my_power(int base, int power) {
    int res = 1;
    for (int i = 0; i < power; i++)
    {
        res *= base;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    cout << my_power(2, n) - 1 << "\n";
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