#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkIfAContainsB(string A, string B) {
    int bIterator = 0;
    for (int i = 0; i < A.length(); i++) {
        if(A[i] == B[bIterator]) {
            bIterator++;
            if(bIterator >= B.length()) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string A, B;
    vector<vector<char>> groupedA;
    int steps = 0;

    cin >> A >> B;

    // vector<char> currentSameLetters;
    // currentSameLetters.push_back(A[0]);
    // for (int i = 1; i < A.length(); i++) {
    //     if(A[i] == currentSameLetters[0]) {
    //         currentSameLetters.push_back(A[i]);
    //     } else {
    //         groupedA.push_back(currentSameLetters);
    //         currentSameLetters.clear();
    //         currentSameLetters.push_back(A[i]);
    //     }
    // }
    // groupedA.push_back(currentSameLetters);

    vector<int> importantIndexes;

    int bIterator = 0;
    for (int i = 0; i < A.length(); i++) {
        if(A[i] == B[bIterator]) {
            bIterator++;
            importantIndexes.push_back(i);
        }
    }
    

    for (int i = 0; i < A.length(); i++) {
        int num;
        cin >> num;
        if(find(importantIndexes.begin(), importantIndexes.end(), (num - 1)) != importantIndexes.end()) {
            int currentImportantIndex = num - 1, indexOfNextLetterOfCurrentType = -1;
            int indexOfCurrentImportantIndex = find(importantIndexes.begin(), importantIndexes.end(), currentImportantIndex) - importantIndexes.begin();

            for (int j = currentImportantIndex + 1; j < A.length(); j++) {
                if(A[num - 1] == A[j] && find(importantIndexes.begin(), importantIndexes.end(), j) == importantIndexes.end()) {
                    indexOfNextLetterOfCurrentType = j;
                    break;
                }
            }
            
            // if(importantIndexes[indexOfCurrentImportantIndex + 1] > importantIndexes[indexOfCurrentImportantIndex]) {
            //     break;
            // }
            
            if(indexOfNextLetterOfCurrentType != -1)
                importantIndexes[indexOfCurrentImportantIndex] = indexOfNextLetterOfCurrentType;
            else
                break;
        }
        A[num - 1] = A[num - 1] - 32;
        steps++;
    }
    cout << steps;
    return 0;
}