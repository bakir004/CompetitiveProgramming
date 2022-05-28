#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int m, n;

string toBin(int num) {
    string s = "";
    while(num > 0) {
        if(num % 2 == 0) {
            s += "0";
        } else {
            s += "1";
        }
        num /= 2;
    }
    while(s.length() < n) {
        s+="0";
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    string s;
    cin >> m >> n >> s;

    int counter = 0;
    bool flag = true;
    for (int i = 0; i < pow(2, n); i++) {
        string bin = toBin(i);
        cout << bin << "\n";
        // flag = true;
        // for (int j = 0; j < n - m + 1; j++) {
        //     string sub = bin.substr(j, m);
        //     if(s == sub) {
        //         flag = false;
        //         break;
        //     }
        // }
        // if(flag) {
        //     counter++;
        // }
        // if(counter > 2021) {
        //     counter = counter % 2021;
        // }
    }

    for (int i = 0; i < pow(2, n); i++) {
        /* code */
    }
    
    
    cout << counter;

    return 0;
}