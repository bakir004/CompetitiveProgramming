#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visited;

struct Connection {
    int from;
    int to;

    Connection(int f, int t) {
        from = f;
        to = t;
    }
};

vector<vector<int>> makeGraph(vector<Connection> connections, int n) {
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < connections.size(); i++) {
        graph[connections[i].from].push_back(connections[i].to);
        graph[connections[i].to].push_back(connections[i].from);
    }
    return graph;
}   

void bfs(vector<vector<int>> graph, int src) {
    queue<int> q;
    visited[src] = true;
    q.push(src);

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i < graph[current].size(); i++) {
            if(!visited[graph[current][i]]) {
                q.push(graph[current][i]);
                visited[graph[current][i]] = true;
            }
        }
    }
}

int main() {
    vector<Connection> connections;

    int n, m;

    cin >> n >> m;

    if(m == 0) {
        cout << n - 1;
        return 0;
    }

    for (int i = 0; i < m; i++) {
        int f, t;
        cin >> f >> t;
        connections.push_back(Connection(f,t));
    }

    for (int i = 0; i < n; i++) {
        visited.push_back(false);
    }

    vector<vector<int>> graph = makeGraph(connections, n);

    int counter = -1;
    for (int i = 0; i < n; i++) {
        if(!visited[i]) {
            bfs(graph, i);
            counter++;
        }
    }
    cout << counter;
    

    return 0;
}