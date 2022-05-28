#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> cif[10];
    vector<int> broj(n, 0);
    vector<int> izbrisan(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> broj[i];
        cif[broj[i]].push_back(i);
    }

    int pos = 0;
    while (pos < n)
    {
        if (pos + k >= n)
        {
            izbrisan[pos] += 1;
            break;
        }

        for (int d = 0; d < 10; d++)
        {
            int curr = lower_bound(cif[d].begin(), cif[d].end(), pos) - cif[d].begin();
            if (curr >= cif[d].size()) continue;
            curr = cif[d][curr];

            if (curr <= pos + k)
            {
                izbrisan[pos] += 1;
                izbrisan[curr] -= 1;

                k -= curr - pos;
                pos = curr + 1;
                break;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        izbrisan[i] += izbrisan[i - 1];
    }

    for (int i = 0; i < n; i++)
        if (!izbrisan[i])
            cout << broj[i] << " ";

    cout << endl;

    return 0;
}
