#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n, power;
    cin >> n;
    bool found = false;

    for (int i = n; i > 2; i--) {
        int j = 2;
        while(true) {
            int root = pow(n, (float)1/(float)j);
            power = pow(root, j);
            if(power == i) {
                found = true;
                break;
            }
            if(root == 1) {
                break;
            }
            j++;
        }
        if(found) {
            break;
        }
    }
    cout << power;
    
    
    return 0;
}