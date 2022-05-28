#include <iostream>
#include <vector>

int main() {
    int n, a, b, years = 0;
    std::vector<int> rankCosts;

    std::cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int d;
        std::cin >> d;
        rankCosts.push_back(d);
    }
    std::cin >> a >> b;

    for (int i = a - 1; i < b - 1; i++)
    {
        years += rankCosts[i];
    }
    std::cout << years;

    return 0;
}