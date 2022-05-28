// STATUS: zavrsen
// IZVOR: EJOI

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Position {
    int x;
    int y;
    // 1 if from right, -1 if from left
    int diagonallyAdjacent = 0;
    bool orthogonallyAdjacent = false;

    Position(int X, int Y) {
        x = X;
        y = Y;
    }

    bool operator==(const Position& pos) {
        return x == pos.x && y == pos.y;
    }

    Position operator+(const Position& pos) {
        return Position(x + pos.x, y + pos.y);
    }
};

int solve(vector<vector<int>> matrix, vector<Position> queryPositions) {
    vector<vector<int>> blockedMatrix(matrix.size(), vector<int>(matrix[0].size(), 0));
    int totalSum = 0;

    for (int i = 0; i < queryPositions.size(); i++) {
        Position currentPos = queryPositions[i];
        blockedMatrix[currentPos.x][currentPos.y] = 1;
    }
    for (int i = 0; i < queryPositions.size(); i++) {
        Position currentPos = queryPositions[i];
        vector<Position> positions = {Position(0,1),Position(0,-1),Position(1,0),Position(-1,0)};

        if(currentPos.diagonallyAdjacent == 0) {
            totalSum += matrix[currentPos.x][currentPos.y];
            if(currentPos.orthogonallyAdjacent) {
                for (int j = 0; j < positions.size(); j++) {
                    Position comparePos = currentPos + positions[j];
                    if(blockedMatrix[comparePos.x][comparePos.y] != 1) {
                        totalSum += matrix[comparePos.x][comparePos.y];
                    }
                }
            } else {
                vector<int> allNums;
                for (int j = 0; j < positions.size(); j++) {
                    Position comparePos = currentPos + positions[j];
                    if(comparePos.x < 0 || comparePos.x >= matrix.size() || comparePos.y < 0 || comparePos.y >= matrix[0].size()) {
                        allNums.push_back(0);
                    } else {
                        allNums.push_back(matrix[comparePos.x][comparePos.y]);
                    }
                }
                int minIndex = min_element(allNums.begin(), allNums.end()) - allNums.begin();
                for (int i = 0; i < allNums.size(); i++) {
                    if(i != minIndex) {
                        totalSum += allNums[i];
                    }
                }
            }
        } else {
            totalSum += matrix[currentPos.x][currentPos.y];
            for (int j = 0; j < positions.size(); j++) {
                Position comparePos = currentPos + positions[j];
                Position currentOffset = positions[j];
                if(!(currentOffset == Position(0, currentPos.diagonallyAdjacent))) {
                    totalSum += matrix[comparePos.x][comparePos.y];
                }
            }
        }
    }
    return totalSum;
}

bool findAdjacentPos(vector<Position> positions, Position comparePos) {
    return find(positions.begin(), positions.end(), comparePos) != positions.end();
}

bool checkIfValidPositions(vector<Position> &positions, int rows, int columns) {
    vector<Position> diagonallyAdjacentPositions = {Position(1,1), Position(-1,1), Position(-1,-1), Position(1,-1)};
    vector<Position> orthogonallyAdjacentPositions = {Position(0,1), Position(-1,0), Position(0,-1), Position(1,0)};
    int adjacentPosCounter = 0;
    for (int i = 0; i < positions.size(); i++) {
        if((positions[i].x == 0 && positions[i].y == 0) || (positions[i].x == rows - 1 && positions[i].y == columns - 1) || (positions[i].x == 0 && positions[i].y == columns - 1) || (positions[i].x == rows - 1 && positions[i].y == 0)) {
            return false;
        }

        for (int j = 0; j < diagonallyAdjacentPositions.size(); j++) {
            if(findAdjacentPos(positions, positions[i] + diagonallyAdjacentPositions[j])) {
                adjacentPosCounter++;
                positions[i].diagonallyAdjacent = diagonallyAdjacentPositions[j].x;
                if(adjacentPosCounter >= 2) return false;
            }
        }
        for (int j = 0; j < orthogonallyAdjacentPositions.size(); j++) {
            if(findAdjacentPos(positions, positions[i] + orthogonallyAdjacentPositions[j])) {
                adjacentPosCounter++;
                positions[i].orthogonallyAdjacent = true;
                if(adjacentPosCounter >= 2) return false;
            }
        }

        adjacentPosCounter = 0;
    }
    return true;
}

int main() {
    int rows = 5, columns = 6, queryNumber = 3;
    vector<Position> positions = {Position(0,1), Position(2,2),  Position(3,4)};
    vector<vector<int>> matrix = {
        {7,3,8,1,0,9},
        {4,6,2,5,8,3},
        {1,9,7,3,9,5},
        {2,6,8,4,5,7},
        {3,8,2,7,3,6}
    };

    // cin >> rows >> columns;

    // vector<vector<int>> matrix(rows, vector<int>(columns, 0));

    // for (int i = 0; i < matrix.size(); i++) {
    //     for (int j = 0; j < matrix[i].size(); j++) {
    //         cin >> matrix[i][j];
    //     }
    // }

    // for (int i = 0; i < queryNumber; i++)
    // {
    //     int x,y;
    //     cin >> x >> y;
    //     positions.push_back(Position(x,y));
    // }

    if(checkIfValidPositions(positions, rows, columns)) {
        cout << solve(matrix, positions);
    } else {
        cout << "No";
    }
    return 0;
}