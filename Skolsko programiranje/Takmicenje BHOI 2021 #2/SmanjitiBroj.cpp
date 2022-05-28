#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    vector<int> numbers;
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }
    // vector<int> res;
    int iteratorBegin = 0;
    int smallestFoundElements = 0;
    while(k > 0) {
        int indexOfMin = min_element(numbers.begin() + smallestFoundElements , numbers.end()) - numbers.begin();
        if(indexOfMin - smallestFoundElements <= k) {
            for (int j = 0; j < indexOfMin - smallestFoundElements; j++) {
                numbers.erase(numbers.begin() + smallestFoundElements);
            }
            k -= (indexOfMin - smallestFoundElements);
            smallestFoundElements++;
        } else {
            for (int j = 0; j < k; j++) {
                int indexOfMax = max_element(numbers.begin() + smallestFoundElements, numbers.end()) - numbers.begin();
                numbers.erase(numbers.begin() + indexOfMax);
                k--;
            }
        }
    }

    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    
    
    
    return 0;
}