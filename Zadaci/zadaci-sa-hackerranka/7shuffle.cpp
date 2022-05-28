#include <iostream>

int main() {
    int ballIndex;

    std::cin >> ballIndex; // 2

    for (int i = 0; i < 3; i++)
    {
        int swap1, swap2;
        std::cin >> swap1 >> swap2; // 2 3
        if(swap1 == ballIndex)
            ballIndex = swap2;
        else if (swap2 == ballIndex)
            ballIndex = swap1;
    }
    std::cout << ballIndex;
 
    return 0;
}