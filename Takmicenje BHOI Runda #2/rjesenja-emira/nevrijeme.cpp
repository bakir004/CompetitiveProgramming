#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g;
vector<bool> visited;

void floodfill(int u)
{
    visited[u] = 1;

    for (int i = 0; i < g[u].size(); i++)
        if (!visited[g[u][i]])
            floodfill(g[u][i]);
}

int main()
{
    int n, m;
    cin >> n >> m;

    g.assign(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    visited.assign(n, 0);
    int ccs = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ccs++;
            floodfill(i);
        }
    }

    cout << ccs - 1 << endl;

    return 0;
}
