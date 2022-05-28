// STATUS: zavrsen
// IZVOR: KTSS-2015

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    fstream file;
    vector<vector<string>> contestants(1001, vector<string>());
    int n, place, numberOfContestants = 0;
    file.open("C:\\Users\\Zakir\\Desktop\\cpp stvari\\zadaci\\hackaton.txt", ios::in);
    file >> n;
    
    for (int i = 0; i < n; i++) {
        string name;
        int points;
        file >> name >> points;
        contestants[points].push_back(name);
        numberOfContestants++;
    }
    file >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        file >> name;
        place = 1;
        bool found = false;
        for (int j = contestants.size() - 1; j >= 0; j--) {
            if(contestants[j].size() != 0) {
                if(find(contestants[j].begin(), contestants[j].end(), name) != contestants[j].end()) {
                    cout << "Osvojili ste " << j << " bodova. Nalazite se na " << place << " mjestu od " << numberOfContestants << " takmicara.\n";
                    found = true;
                }
                if(j == 0 && found == false) {
                    cout << "Nepoznata sifra\n";
                }
                place+=contestants[j].size();
            }
        }
    }
    file.close();
    return 0;

}
