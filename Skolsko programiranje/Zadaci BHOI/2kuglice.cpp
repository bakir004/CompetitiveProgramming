#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int solve(vector<char> balls) {
    int sum = 0;
    stack<char> letterStack;
    stack<int> indexStack;
    for (int i = 0; i < balls.size(); i++) {
        char target = balls[i] == 'B' ? 'C' : 'B';
        
        if(!letterStack.empty() && letterStack.top() == target) {
            sum += i - indexStack.top();
            indexStack.pop();
            letterStack.pop();
        } else {
            letterStack.push(balls[i]);
            indexStack.push(i);
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<char> balls;

    for (int i = 0; i < n * 2; i++) {
        char letter;
        cin >> letter;
        balls.push_back(letter);
    }

    cout << solve(balls);
    

    return 0;
}