// STATUS: nezavrsen
// IZVOR: KTSS-2016

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> getGoodPyramids(int minN, int maxN) {
    vector<int> sums;
    int sum, level = 1;
    while(true) {
        sum = 0;
        for (int i = 1; i <= level; i++) {
            sum += (i * (i + 1)) / 2;
        }
        level++;
        if(sum >= minN && sum <= maxN) {
            sums.push_back(sum);
        }
        
        if(sum > maxN) {
            break;
        }
    }
    return sums;
}

set<int> toSet(vector<int> vector) {
    set<int> set;
    for (int i = 0; i < vector.size(); i++) {
        set.insert(vector[i]);
    }
    return set;
}

int main() {
    int minN, maxN;

    cin >> minN >> maxN;

    vector<int> sumsVector = getGoodPyramids(minN, maxN);
    set<int> sumsSet = toSet(sumsVector);

    for (int i = minN; i <= maxN; i++) {
        int currentDiff;
        for (int j = 0; j < sumsVector.size(); j++) {
            if(i > sumsVector[j]) {
                currentDiff = i - sumsVector[j];
                if(find(sumsSet.begin(), sumsSet.end(), currentDiff) != sumsSet.end()) {
                    cout << i << "\n";
                }
            }
        }
    }

    return 0;
}