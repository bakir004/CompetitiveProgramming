#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int index = 3;
    int left = 0, right = 0;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if(i == index) {
            if(c == '+') {
                right++;
            } else {
                left++;
            }
            index+=4;
        }
    }
    cout << min(right, left);
    

    return 0;
}