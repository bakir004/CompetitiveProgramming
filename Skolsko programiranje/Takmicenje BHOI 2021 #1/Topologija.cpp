// Osvojeno bodova: 70/100
// Tacnih testcase-ova: 17/22

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<int, bool> visited;

struct Connection {
    int from, to;

    Connection(int f, int t) {
        from = f;
        to = t;
    }
};

vector<vector<int>> makeGraph(vector<Connection> connections, int N) {
    vector<vector<int>> graph(N + 1, vector<int>());
    for (int i = 0; i < connections.size(); i++) {
        graph[connections[i].from].push_back(connections[i].to);
        graph[connections[i].to].push_back(connections[i].from);
    }
    return graph;
}

vector<int> bfs(vector<vector<int>> graph, int src) {
    queue<int> q;
    q.push(src);
    vector<int> idsOfThisGraph;
    idsOfThisGraph.push_back(src);
    visited[src] = true;

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i < graph[current].size(); i++) {
            if(!visited[graph[current][i]])  {
                q.push(graph[current][i]);
                visited[graph[current][i]] = true;
                idsOfThisGraph.push_back(graph[current][i]);
            }
        }
    }
    return idsOfThisGraph;
}

int main() {
    int N, M;
    vector<Connection> connections;

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        connections.push_back(Connection(num1, num2));
    }
    
    vector<vector<int>> graph = makeGraph(connections, N);

    int ring = 0, linear = 0, star = 0; 

    for (int i = 1; i <= N; i++) {
        if(!visited[i]) {
            vector<int> thisGraph = bfs(graph, i);
            if(thisGraph.size() > 1) {
                bool everyoneHas2Connections = true;
                for (int j = 0; j < thisGraph.size(); j++) {
                    if(graph[thisGraph[j]].size() != 2) {
                        everyoneHas2Connections = false;
                        break;
                    }
                }
                if(everyoneHas2Connections) {
                    ring++;
                    continue;
                }
                bool isLinear = true;
                int singleConnections = 0;
                for (int j = 0; j < thisGraph.size(); j++) {
                    if(graph[thisGraph[j]].size() == 1) {
                        singleConnections++;
                    } else if(graph[thisGraph[j]].size() != 2) {
                        isLinear = false;
                        break;
                    }
                }
                if(singleConnections == 2 && isLinear) {
                    linear++;
                    continue;
                }
                singleConnections = 0;
                for (int j = 0; j < thisGraph.size(); j++) {
                    if(graph[thisGraph[j]].size() == 1) {
                        singleConnections++;
                    }
                }
                if(singleConnections == thisGraph.size() - 1) {
                    star++;
                    continue;
                }
            }
        }
    }
    cout << linear << " " << ring << " " << star;
    

    return 0;
}