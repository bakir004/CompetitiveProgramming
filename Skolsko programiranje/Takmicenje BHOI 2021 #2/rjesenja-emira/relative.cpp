#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> p;
vector<vector<int> > stablo;
int numLeaves;
vector<bool> isLeaf;
vector<int> lengths;

vector<long long> mySum;
vector<int> myLeavesSize;

vector<long long> myRealSum;

void dfs(int u)
{
    myLeavesSize[u] = 0;
    mySum[u] = 0LL;

    for (int i = 0; i < stablo[u].size(); i++)
    {
        int v = stablo[u][i];

        if (isLeaf[v])
        {
            mySum[u] += lengths[v];
            myLeavesSize[u]++;
        }
        else
        {
            dfs(v);

            myLeavesSize[u] += myLeavesSize[v];
            mySum[u] += mySum[v] + myLeavesSize[v] * (lengths[v] + 1LL);
        }
    }
}

void DFS(int u)
{
    if (u != 0)
    {
        myRealSum[u] = mySum[u];
        myRealSum[u] += myRealSum[p[u]] - (mySum[u] + myLeavesSize[u] * (lengths[u] + 1LL));
        myRealSum[u] += (numLeaves - myLeavesSize[u]) * 3LL;
    }
    else
        myRealSum[u] = mySum[u];

    for (int i = 0; i < stablo[u].size(); i++)
        if (!isLeaf[stablo[u][i]])
            DFS(stablo[u][i]);
}

int main()
{
    cin >> n;

    p.assign(n, 0);
    stablo.assign(n, vector<int>());
    numLeaves = 0;
    isLeaf.assign(n, 0);
    lengths.assign(n, 0);

    for (int i = 0; i < n; i++)
    {
        string name; int m;
        cin >> name >> m;
        lengths[i] = name.length();

        if (m > 0)
        {
            for (int j = 0; j < m; j++)
            {
                int v;
                cin >> v;
                v--;

                p[v] = i;
                stablo[i].push_back(v);
            }
        }
        else
        {
            isLeaf[i] = 1;
            numLeaves++;
        }
    }

    mySum.assign(n, 0LL);
    myLeavesSize.assign(n, 0);
    dfs(0);

    myRealSum.assign(n, LLONG_MAX);
    DFS(0);

    long long minimum = min_element(myRealSum.begin(), myRealSum.end()) - myRealSum.begin();
    //cout << minimum << " ";
    cout << myRealSum[minimum] << endl;

    return 0;
}
