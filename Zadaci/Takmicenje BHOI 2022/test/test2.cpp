#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> pozivi(q, 0);
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        pozivi[a]++;
        pozivi[b]--;
    }
    


    return 0;
}