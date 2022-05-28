// STATUS: zavrsen
// IZVOR: EJOI

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int solve(vector<int> diameter, vector<int> capacity, int tap, int volume) {
    int currentFountain = tap - 1;
    bool foundNextFountain = false;
    while(volume > 0) {
        volume -= capacity[currentFountain];
        if(volume <= 0) {
            return currentFountain + 1;
        }
        for (int i = currentFountain; i < diameter.size(); i++) {
            if(diameter[i] > diameter[currentFountain]) {
                currentFountain = i;
                foundNextFountain = true;
                break;
            }
        }
        if(!foundNextFountain && volume > 0) {
            return 0;
        }
    }
    return currentFountain + 1;
}

int main() {
    int N, Q;
    vector<int> diameter;
    vector<int> capacity;
    vector<pair<int,int>> queries;

    fstream file;
    file.open("C:\\Users\\Zakir\\Desktop\\cpp stvari\\zadaci\\fountain.txt", ios::in);
    file >> N >> Q;

    for (int i = 0; i < N; i++) {
        int d, c;
        file >> d >> c;
        diameter.push_back(d);
        capacity.push_back(c);
    }
    for (int i = 0; i < Q; i++) {
        int r, v;
        file >> r >> v;
        queries.push_back({r, v});
    }

    file.close();

    for (int i = 0; i < queries.size(); i++) {
        cout << solve(diameter, capacity, queries[i].first, queries[i].second) << "\n";
    }

    return 0;
}