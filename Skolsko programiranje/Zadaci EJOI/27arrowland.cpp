// STATUS: zavrsen
// IZVOR: EJOI

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

struct Node {
    vector<int> neighbours;
    vector<int> costs;
    // neighbours[i] odgovara costs[i]
    Node() {
        neighbours = {};
        costs = {};
    }
    Node(vector<int> _n, vector<int> _c) {
        neighbours = _n;
        costs = _c;
    }
};

typedef map<int, Node> graphType;

graphType makeGraph(vector<vector<char>> matrix) {
    vector<int> currentNeighbours;
    vector<int> currentCosts;
    map<int, Node> graph;
    Node currentNode;
    vector<char> directions = {'W', 'N', 'E', 'S'};
    int idCounter = 1;
    vector<vector<int>> idMatrix(matrix.size(), vector<int>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if(matrix[i][j] != 'X' || (matrix[i][j] == 'X' && (i == matrix.size() - 1 && j == matrix[0].size() - 1))) {
                idMatrix[i][j] = idCounter;
                idCounter++;
            }
        }
    }
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if(matrix[i][j] != 'X') {
                currentNeighbours.clear();
                currentCosts.clear();
                vector<vector<int>> indexes = {{i, j - 1}, {i - 1,j}, {i, j + 1}, {i + 1, j}};
                char adjacentChar, currentChar = matrix[i][j];

                for (int k = 0; k < indexes.size(); k++) {
                    if(indexes[k][0] >= 0 && indexes[k][0] < matrix.size() && indexes[k][1] >= 0 && indexes[k][1] < matrix[i].size()) {
                        adjacentChar = matrix[indexes[k][0]][indexes[k][1]];
                        if(adjacentChar != 'X' || (adjacentChar == 'X' && (indexes[k][0] == matrix.size() - 1 && indexes[k][1] == matrix[0].size() - 1))) {
                            currentNeighbours.push_back(idMatrix[indexes[k][0]][indexes[k][1]]);
                            int targetIndex = k;
                            int currentIndex = find(directions.begin(), directions.end(), currentChar) - directions.begin();
                            if(targetIndex >= currentIndex) {
                                currentCosts.push_back(targetIndex - currentIndex);
                            } else {
                                currentCosts.push_back(targetIndex - currentIndex + 4);
                            }
                        }
                    }
                }
                graph.emplace(idMatrix[i][j], Node(currentNeighbours, currentCosts));
            }
        }
    }
    return graph;
}

int dijkstra(graphType graph, int endNode) {
    priority_queue<pair<int, int>> q;
    vector<int> distance;

    for (int i = 0; i <= graph.size(); i++) {
        distance.push_back(INT_MAX);
    }
    
    q.push(make_pair(distance[0], 1));
    distance[1] = 0;
    while(!q.empty()) {
        int currentNode = q.top().second;
        q.pop();
        for (int i = 0; i < graph[currentNode].neighbours.size(); i++) {
            int neighbour = graph[currentNode].neighbours[i];
            int distanceToNeighbour = graph[currentNode].costs[i];
            int pathCost = distance[currentNode] + distanceToNeighbour;

            if (distance[neighbour] > pathCost) {
                distance[neighbour] = pathCost;
                q.push(make_pair(distance[neighbour], neighbour));
            }
        }
    }
    return distance[endNode];
}

int main() {
    int t, m, n;
    fstream file;
    file.open("C:\\Users\\Zakir\\Desktop\\cpp stvari\\zadaci\\arrowland.txt", ios::in);

    file >> m >> n;

    vector<vector<char>> matrix(m, vector<char>(n, '0'));

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            file >> matrix[i][j];
        }
    }

    file.close();

    int endNodeId = m * n + 1;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if(matrix[i][j] == 'X') {
                endNodeId--;
            }
        }
    }
    

    graphType graph = makeGraph(matrix);

    int totalCost = dijkstra(graph, endNodeId);

    cout << totalCost;
    
    

    return 0;
}