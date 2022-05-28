#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int _m, _n;
    // unesemo poluprecnike
    cin >> _m >> _n;
    int m = max(_m,_n), n = min(_m,_n);

    // konstruktorom kreiramo matricu trazene velicine
    vector<vector<char>> matrix(m + 1, vector<char>(2 * m + 1, '-'));

    for(int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            float distance = sqrt(pow(i - m, 2) + pow(j - m, 2));
            if(distance <= m && distance >= n) {
                cout << "*" << " ";
            } else {
                cout << "-" << " ";
            }
        }
        cout << endl;
    }



    return 0;
}