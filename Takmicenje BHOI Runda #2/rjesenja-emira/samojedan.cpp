#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map<int, int> pojavio;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        int p;
        cin >> p;

        pojavio[p]++;
    }

    int nepojavljeni = -1;
    for (map<int, int>::iterator el = pojavio.begin(); el != pojavio.end(); el++)
    {
        pair<int, int> curr = (*el);
        if (curr.second == 1)
        {
            nepojavljeni = curr.first;
            break;
        }
    }

    cout << nepojavljeni << endl;

    return 0;
}
