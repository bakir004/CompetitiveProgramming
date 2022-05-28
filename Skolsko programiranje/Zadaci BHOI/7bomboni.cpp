#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    vector<short> balls;
    
    cin >> N;

    for (int i = 0; i < N; i++){
        short num;
        cin >> num;
        balls.push_back(num);
    }

    short minIndex = min_element(balls.begin(), balls.end()) - balls.begin();

    int sum = 0;

    for (int i = 0; i < N; i++){
        i != minIndex ? sum += balls[i] : sum += 0;
    }

    cout << sum;

    return 0;
    
}