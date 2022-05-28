#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    while(n % 10 != 0) {
        n = n * ((n % 10) - 1) / 2;
    }
    cout << n;

    return 0;
}