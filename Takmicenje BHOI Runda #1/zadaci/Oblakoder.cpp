// Osvojeno bodova: 100/100
// Tacnih testcase-ova: 29/29

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> buildings;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        buildings.push_back(num);
    }

    int currentMax = -1;
    int numberOfMaxItems = 0;
    for (int i = 0; i < buildings.size(); i++) {
        if(buildings[i] > currentMax) {
            currentMax = buildings[i];
            numberOfMaxItems = 1;
        } else if (buildings[i] == currentMax) {
            numberOfMaxItems++;
        }
    }
    
    long long maxSum = -1;
    if(numberOfMaxItems == 1) {
        cout << buildings.size();
    } else {
        for (int i = 0; i < buildings.size(); i++) {
            if(buildings[i] == currentMax) {
                long long sum = 1;
                int pointer1 = i - 1, pointer2 = i + 1;
                while(pointer1 >= 0) {
                    if(buildings[pointer1] != currentMax) {
                        sum++;
                        pointer1--;
                        if(pointer1 < 0) {
                            break;
                        }
                    } else {
                        sum++;
                        break;
                    }
                }
                while(pointer2 < buildings.size()) {
                    if(buildings[pointer2] != currentMax) {
                        sum++;
                        pointer2++;
                        if(pointer2 >= buildings.size()) {
                            break;
                        }
                    } else {
                        sum++;
                        break;
                    }
                }
                maxSum = max(sum, maxSum);
            }
        }
        cout << maxSum;
    }
    return 0;
}