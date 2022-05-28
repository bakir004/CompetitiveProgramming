#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> kutije(n, 0);
    vector<bool> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> kutije[i];
    }
    
    int groups = 0;
    for (int i = 0; i < n; i++)
    {
        if(visited[i])
            continue;

        visited[i] = true;
        groups++;
        if(groups>2) {
            cout << -1;
            return 0;
        }

        int gcd = kutije[i];
        for (int j = i + 1; j < n; j++)
        {
            if(__gcd(gcd, kutije[j]) != 1) {
                gcd = __gcd(gcd, kutije[j]);
                visited[j] = true;
            }
        }
    }

    cout << groups;

    return 0;
}