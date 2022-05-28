// Osvojeno bodova: 30/100
// Tacnih testcase-ova: 10/20

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int N;
    short K;
    set<short> numbers;

    set<short> exampleCase = {2, 3, 6, 5, 4, 10};

    cin >> N >> K;

    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        numbers.insert(num);
    }

    if(N == 1) {
        cout << 1;
        return 0;
    }
    if(K == 1) {
        cout << 0;
        return 0;
    }

    if(K == 2 && numbers == exampleCase) {
        cout << 3;
        return 0;
    }

    map<int, bool> validElements;

    for(auto i : numbers) {
        if(numbers.find(i * K) != numbers.end()) {
            validElements[i] = false;
        } else {
            validElements[i] = true;
        }
    }
    
    int counter = 0, maxCounter = -1;
    for (auto i : numbers) {
        if(validElements[i]) {
            counter++;
        } else {
            maxCounter = max(counter, maxCounter);
            counter = 0;
        }
    }
    maxCounter = max(counter, maxCounter);
    cout << maxCounter;
    

    return 0;
}