#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, d, arrangements = 0;
    std::vector<int> soldiers;

    std::cin >> n >> d;

    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        soldiers.push_back(num);
    }
    
    std::sort(soldiers.begin(), soldiers.end());

    for (int i = 0; i < soldiers.size() - 1; i++)
    {
        if(abs(soldiers[i] - soldiers[i + 1]) <= d)
            arrangements += 2;
    }

    std::cout << arrangements;
     
    return 0;
}