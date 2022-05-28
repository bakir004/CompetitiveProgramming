#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

map<int, vector<int>> graph;

void removeSingleNodes() {
    queue<int> q;
    for(auto node : graph) {
        int myId = node.first;
        if(node.second.size() == 1) {
            q.push(myId);
        }
    }
    while(!q.empty()) {
        int myId = q.front();
        q.pop();
        if(graph[myId].size() <= 0)
            continue;
        int childId = graph[myId][0];

        graph[myId] = {};
        vector<int> neighbours = graph[childId];
        auto iterator = find(neighbours.begin(), neighbours.end(), myId);
        neighbours.erase(iterator);
        graph[childId] = neighbours;
        if(graph[childId].size() == 1) {
            q.push(childId);
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    removeSingleNodes();

    int counter = 0;
    for(auto node : graph) {
        if(node.second.size() > 1) {
            counter++;
        }
    }
    cout << counter;

    return 0;
}