#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>> matrix) {
    int surface = matrix.size() * matrix[0].size() * 2;
    int currentSurfaceSum = 0, topDiff, bottomDiff, leftDiff, rightDiff;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            int indexLeft = j - 1;
            int indexTop = i - 1;
            int indexRight = j + 1;
            int indexBottom = i + 1;

            int elementLeft;
            int elementTop;
            int elementRight;
            int elementBottom;

            if(indexLeft < 0) {
                elementLeft = 0;
            } else {
                elementLeft = matrix[i][indexLeft];
            }

            if(indexTop < 0) {
                elementTop = 0;
            } else {
                elementTop = matrix[indexTop][j];
            }

            if(indexRight >= matrix[i].size()) {
                elementRight = 0;
            } else {
                elementRight = matrix[i][indexRight];
            }
            
            if(indexBottom >= matrix.size()) {
                elementBottom = 0;
            } else {
                elementBottom = matrix[indexBottom][j];
            }


            topDiff = matrix[i][j] - elementTop;
            if(topDiff < 0) {
                topDiff = 0;
            }
            bottomDiff = matrix[i][j] - elementBottom;
            if(bottomDiff < 0) {
                bottomDiff = 0;
            }
            rightDiff = matrix[i][j] - elementRight;
            if(rightDiff < 0) {
                rightDiff = 0;
            }
            leftDiff = matrix[i][j] - elementLeft;
            if(leftDiff < 0) {
                leftDiff = 0;
            }

            currentSurfaceSum = currentSurfaceSum + topDiff + bottomDiff + rightDiff + leftDiff;
            surface += currentSurfaceSum;
            currentSurfaceSum = 0;
        }
    }
    return surface;
}

int main() {
    int h, w;

    cin >> h >> w;

    vector<vector<int>> matrix(h, vector<int>(w, 0));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> matrix[i][j];
        }
    }

    // int h, w;

    // vector<vector<int>> matrix {
    //     {1,2,3},
    //     {3,2,1},
    //     {1,2,3},
    //     {3,2,1}
    // };

    cout << solve(matrix);
}

