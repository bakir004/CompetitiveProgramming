#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if(num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0)
            return false;
    }
    return true;
}

int diagonalDifference(vector<vector<int>> matrix) {
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < matrix.size(); i++) {

        if(isPrime(matrix[i][i]))
            sum1 += matrix[i][i];
    }
    for (int i = 0; i < matrix.size(); i++) {
        int j = matrix.size() - i - 1;

        if(isPrime(matrix[i][j]))
            sum2 += matrix[i][j];
    }

    return abs(sum1 - sum2);
}

int main() {
    int n;

    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << diagonalDifference(matrix);
}