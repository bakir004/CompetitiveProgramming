#include <iostream>

int main() {
    int t, n, steps;

    std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        while(n > 1) {
            if(n % 6 == 0)
                n /= 6;
            else
                n *= 2;

            steps++;
        }
        std::cout << steps << "\n\n";
    }
}