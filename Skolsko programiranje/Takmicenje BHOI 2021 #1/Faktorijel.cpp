// Osvojeno bodova: 70/100
// Tacnih testcase-ova: 18/25

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> res;
    long long N;
    cin >> N;

    int currentFactorielResult = 1, factor = 2;
    int currentFactoriel = 1;
    while(currentFactorielResult <= N) {
        currentFactorielResult *= factor;
        currentFactoriel++;
        factor++;
    }
    factor--;
    currentFactorielResult /= factor;
    currentFactoriel--;

    while(true) {
        int counter = 0;
        while(true) {
            if(N - currentFactorielResult < 0) {
                break;
            }
            N -= currentFactorielResult;
            counter++;
        }
        res.push_back(counter);
        if(N <= 0 && factor == 2) {
            break;
        }
        factor--;
        currentFactorielResult /= factor;
    }
    cout << res.size() << "\n";
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    

    return 0;
}