#include <vector>
#include <iostream>
#include <utility>
#include <bitset>
#include <algorithm>

using namespace std;

int n;
vector<vector<int> > stablo;
vector<pair<int, int> > edgeList;

bitset<16> taken;
vector<int> currChoice;

bitset<16> edgeExists;

bitset<16> checkCurrNode(int x)
{
    bitset<16> newEdges(0);
    bool noneAreChosenYet = 1;
    for (int i = 0; i < stablo[x].size(); i++)
    {
        int y = stablo[x][i];
        if (currChoice[y] > 0)
        {
            noneAreChosenYet = 0;
            int diff = abs(currChoice[x] - currChoice[y]);
            if (edgeExists[diff] | newEdges[diff])
                return bitset<16>(0);

            newEdges[diff] = 1;
        }
    }

    newEdges[0] = noneAreChosenYet;

    return newEdges;
}

bool backtrack(int x)
{
    if (x == n)
        return 1;

        if (taken[1] && !taken[n])
        {
            bool has1 = 0;
            int one = -1;
            for (int j = 0; j < stablo[x].size(); j++)
                if (currChoice[stablo[x][j]] == 1) { has1 = 1; one = stablo[x][j];  break; }

            if (has1)
            {
                int numChosen = 0;
                bool hasN = 0;
                for (int j = 0; j < stablo[one].size(); j++)
                    if (currChoice[stablo[one][j]] > 0) {
                        numChosen++;
                        if (currChoice[stablo[one][j]] == n) {
                            hasN = 1;
                            break;
                        }
                    }

                if (!hasN && numChosen == stablo[one].size() - 1)
                {
                    currChoice[x] = n;
                    bitset<16> check = checkCurrNode(x);
                    if (check.any())
                    {
                        taken[n] = 1;
                        edgeExists |= check;

                        bool ans = backtrack(x + 1);
                        if (ans) return 1;

                        taken[n] = 0;
                        edgeExists ^= check;
                    }

                    currChoice[x] = 0;
                    return 0;
                }
            }
        }

    for (int i = 1; i <= n; i++)
    {
        //if (x == 0 && i >= n / 2) break; // medjutim ovo me nece ubrzat jer cemo mi svakako do n/2 naci valjano stablo
        if (taken[i]) continue;

        currChoice[x] = i;
        bitset<16> check = checkCurrNode(x);
        if (check.any())
        {
            taken[i] = 1;
            edgeExists |= check;

            bool ans = backtrack(x + 1);
            if (ans) return 1;

            taken[i] = 0;
            edgeExists ^= check;
        }

        currChoice[x] = 0;
    }

    return 0;
}

void init()
{
    taken = bitset<16>(0);
    currChoice.assign(n, 0);
    edgeExists = bitset<16>(0);
}

int main()
{
    cin >> n;

    stablo.assign(n, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        stablo[u].push_back(v);
        stablo[v].push_back(u);
        edgeList.push_back(make_pair(u, v));
    }

    for (int i = 0; i < n; i++)
        sort(stablo[i].begin(), stablo[i].end());

    init();
    backtrack(0);

    for (int i = 0; i < n; i++)
        cout << i << " " << currChoice[i] << endl;
    for (int i = 0; i < n - 1; i++)
        cout << edgeList[i].first << " " << edgeList[i].second << " " << abs(currChoice[edgeList[i].first] - currChoice[edgeList[i].second]) << endl;

    return 0;
}
