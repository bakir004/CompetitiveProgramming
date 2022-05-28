#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

struct FileInfo {
    int myCost;
    vector<int> neighbours;
    vector<int> costToNeighbours;
    int costToParent;
    int parentId;

    FileInfo() {
        myCost = -1;
    }
    FileInfo(int c) {
        myCost = c;
    }
};

long long dijkstra(vector<FileInfo> fileInfo, int src) {
    vector<long long> dist(fileInfo.size(), INT_FAST32_MAX);
    vector<bool> visited(fileInfo.size(), false);
    priority_queue<pair<int, int>> q;
    dist[src] = 0;
    dist[0] = 0;
    q.push(make_pair(dist[src], src));
    long long sum = 0;
    visited[src] = true;

    while(!q.empty()) {
        int current = q.top().second;
        q.pop();
        if(current == 0) {
            continue;
        }

        if(fileInfo[current].neighbours.size() == 0) {
            sum += dist[current];
        }

        for (int i = 0; i < fileInfo[current].neighbours.size(); i++) {
            int neighbourId = fileInfo[current].neighbours[i];
            if(dist[current] + fileInfo[current].costToNeighbours[i] <= dist[neighbourId] && !visited[neighbourId]) {
                if(current != src) {
                    dist[neighbourId] = dist[current] + fileInfo[current].costToNeighbours[i];
                } else {
                    dist[neighbourId] = 0;
                }
                dist[neighbourId] += fileInfo[neighbourId].myCost;
            }
            if(!visited[neighbourId]) {
                q.push(make_pair(dist[neighbourId], neighbourId));
                visited[neighbourId] = true;
            }
        }
        if(dist[current] + fileInfo[current].costToParent < dist[fileInfo[current].parentId]) {
            dist[fileInfo[current].parentId] = dist[current] + fileInfo[current].costToParent;
            q.push(make_pair(dist[fileInfo[current].parentId], fileInfo[current].parentId));
            visited[fileInfo[current].parentId] = true;
        }
    }
    return sum;
}

vector<FileInfo> bfs(vector<FileInfo> fileInfo, int src) {
    vector<bool> visited(fileInfo.size(), false);
    queue<int> q;
    visited[src] = true;
    q.push(src);

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i < fileInfo[current].neighbours.size(); i++) {
            int neighbourId = fileInfo[current].neighbours[i];
            if(!visited[neighbourId]) {
                visited[neighbourId] = true;
                q.push(neighbourId);
            }
            fileInfo[neighbourId].parentId = current;
        }
    }
    return fileInfo;
}

int main() {
    int n;

    cin >> n;

    vector<FileInfo> fileInfo(n + 1, FileInfo());
    for (int i = 1; i <= n; i++) {
        vector<int> neighbours;
        vector<int> neighbourCosts;
        string s;
        int numOfNeighbours;
        cin >> s;
        cin >> numOfNeighbours;
        FileInfo info = FileInfo(s.length());
        if(numOfNeighbours > 0) {
            for (int j = 0; j < numOfNeighbours; j++) {
                int neighbourId;
                cin >> neighbourId;
                neighbours.push_back(neighbourId);
                neighbourCosts.push_back(1);
            }
        }
        info.neighbours = neighbours;
        info.costToNeighbours = neighbourCosts;
        info.costToParent = 2;
        fileInfo[i] = info;
    }

    fileInfo = bfs(fileInfo, 1);
    fileInfo[1].parentId = 0;

    long long res = INT_FAST32_MAX;
    for (int i = 1; i <= n; i++) {
        long long temp = dijkstra(fileInfo, i);
        if(temp < res) {
            res = temp;
        }
    }
    
    cout << res;
    
    return 0;
}