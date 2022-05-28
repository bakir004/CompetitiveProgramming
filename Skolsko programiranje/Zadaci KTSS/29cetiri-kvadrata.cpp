#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solve(int n) {
    int N = n;
    static int mainRoot = sqrt(n);
    vector<int> res;

    n -= pow(mainRoot, 2);
    res.push_back(mainRoot);

    while(n > 0) {
        int root = sqrt(n);
        n -= pow(root, 2);
        res.push_back(root);
        if(res.size() > 4) {
            break;
        }
    }
    while(res.size() < 4) {
        res.push_back(0);
    }
    if(res.size() > 4) {
        mainRoot--;
        res.clear();
        return solve(N);
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> res = solve(n);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;   
}