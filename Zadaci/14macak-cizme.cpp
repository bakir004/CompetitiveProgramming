// STATUS: nezavrsen
// IZVOR: BHOI

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

typedef map<int, vector<int>> graphMap;
typedef vector<pair<int, int>> edgeVector;

enum methodType {GO_ALONE, MEET_AND_GO, TOW_AND_GO};

int lesser, bigger, closer, farther, costUntilMet = 0;
int rightCost = 5, leftCost = 9, bothCost = 11;

int bfs(graphMap graph, int begin, int end, int cost, methodType method) {
    queue<int> q;
    map<int, bool> visited;
    map<int, int> levels;
    map<int, int> parents;

    for (auto pair : graph) {
        visited.emplace(pair.first, false);
    }

    q.push(begin);
    levels[begin] = 0;
    visited[begin] = true;
    parents[begin] = 0;
    int currentNode = begin;

    while(!q.empty()) {
        currentNode = q.front();
        q.pop();
        
        if(currentNode == end) {
            break;
        }

        for (int i = 0; i < graph[currentNode].size(); i++) {
            if(!visited[graph[currentNode][i]]) {
                visited[graph[currentNode][i]] = true;
                q.push(graph[currentNode][i]);
                if(method == GO_ALONE) {
                    levels[graph[currentNode][i]] = levels[currentNode] + 1;
                } else if (method == MEET_AND_GO) {
                    parents[graph[currentNode][i]] = currentNode;
                } else {

                }
            }
        }
    }

    vector<int> path = {};
    int currentParent = end;
    
    while(method == MEET_AND_GO) {
        currentParent = parents[currentParent];
        if(currentParent == 0) break;
        path.push_back(currentParent);
    }
    path.pop_back();

    int meetingNode;
    int pathLength = path.size();

    if(method == MEET_AND_GO) {
        if(pathLength == 0) {
            //meetingNode = closer == lesser ? 2 : 3;
            costUntilMet += closer;
        } else if(pathLength == 1) {
            meetingNode = path[0];
            costUntilMet += bigger + lesser;
        } else {
            if(pathLength % 2 == 0) {
                meetingNode = path[pathLength / 2 - 1];
                costUntilMet += (pathLength - (pathLength / 2 - 1)) * lesser;
                costUntilMet += (pathLength - (pathLength - pathLength / 2 - 1) + 1) * bigger;
            } else {
                meetingNode = path[pathLength / 2];
                costUntilMet += (pathLength / 2 + 1) * bigger;
            }
        }
        return meetingNode;
    } else if(method == GO_ALONE) {
        return levels[currentNode] * cost;
    } else {

    }
    return 0;
}

graphMap makeGraph(edgeVector edges) {
    // zakomplikovalo mi se sa vector<vector<int>> pa sam koristio mapu ¯\_(ツ)_/¯
    map<int, vector<int>> graph;
    for (int i = 0; i < edges.size(); i++) {
        graph[edges[i].first] = {};
        graph[edges[i].second] = {};
    }
    for (int i = 0; i < edges.size(); i++) {
        graph[edges[i].first].push_back(edges[i].second);
        graph[edges[i].second].push_back(edges[i].first);
    }
    return graph;
}

int main() {
    int endNodeNum = 5, numOfNodes = 5;
    edgeVector edges = {{1,3},{2,4},{3,4},{3,5},{1,2}};

    // int rightCost, leftCost, bothCost, endNodeNum, numOfNodes;
    // edgeVector edges;

    // cin >> rightCost >> leftCost >> bothCost >> endNodeNum >> numOfNodes;

    // for (int i = 0; i < numOfNodes; i++) {
    //     int a,b;
    //     cin >> a >> b;
    //     edges.push_back(make_pair(a,b));
    // }

    graphMap graph = makeGraph(edges);

    if(leftCost >= rightCost) {
        lesser = rightCost;
        bigger = leftCost;
    } else {
        lesser = leftCost;
        bigger = rightCost;
    }

    int totalCost = 0;

    if(bfs(graph, 1, endNodeNum, rightCost, GO_ALONE) / rightCost <= bfs(graph, 2, endNodeNum, leftCost, GO_ALONE) / leftCost) {
        closer = rightCost;
        farther = leftCost;
    } else {
        closer = leftCost;
        farther = rightCost;
    }

    if(leftCost + rightCost <= bothCost) {
        // svako svojim putem
        totalCost += bfs(graph, 1, endNodeNum, rightCost, GO_ALONE);
        totalCost += bfs(graph, 2, endNodeNum, leftCost, GO_ALONE);
        cout << totalCost;
    } else {
        if(lesser + bothCost >= bigger) {
            // nadju se na sredini i idu zajedno
            int meetingNode;
            if(leftCost == lesser) {
                meetingNode = bfs(graph, 1, 2, leftCost, MEET_AND_GO);
            } else {
                meetingNode = bfs(graph, 2, 1, rightCost, MEET_AND_GO);
            }
            totalCost = costUntilMet + bfs(graph, meetingNode, endNodeNum, bothCost, GO_ALONE);
            cout << totalCost;
        } else {
            // slepanje
        }
    }

    return 0;
}