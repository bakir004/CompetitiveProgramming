#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    map<string, int> m;
    vector<int> res;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        m[s] = i + 1;
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(m[s] == 0) {
            res.push_back(-1);
        } else {
            res.push_back(m[s]);
        }
    }
    
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
    }
    
    

    return 0;
}