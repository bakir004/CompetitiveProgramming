#include <iostream>

int main() {
    unsigned long long int n, k;

    std::cin >> n >> k;
    int mid;
    mid = n / 2;
    if(n % mid == 1) {
        mid++;
    }

    if(k >= mid) {
        std::cout << (k - mid) * 2;
    } else {
        std::cout << k * 2 - 1;
    }
}