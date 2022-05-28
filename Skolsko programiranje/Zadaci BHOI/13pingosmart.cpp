// STATUS: zavrsen
// IZVOR: BHOI

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int numOfLevels, kowalskiTime, pingoTime;
    vector<int> levels;
    int totalTime = 0;

    // int numOfLevels = 7, kowalskiTime = 7, pingoTime = 4;
    // vector<int> levels = {4,0,4,2,6,4,4};

    cin >> numOfLevels >> kowalskiTime >> pingoTime;

    for (int i = 0; i < numOfLevels; i++) {
        int level;
        cin >> level;
        levels.push_back(level);
    }

    sort(levels.begin(), levels.end());

    int levelsCompleted = 0;
    int length = levels.size();

    for (int i = 0; i < length; i++) {
        if(levels[i] <= levelsCompleted) {
            totalTime += pingoTime;
        } else {
            totalTime += kowalskiTime;
            length--;
            i--;
        }
        levelsCompleted++;
    }
    cout << totalTime;

    return 0;
}