#include <iostream>
#include <vector>

using namespace std;

int matrix[2][2] = {0,0,0,0};

int evaluate() {
    if(matrix[0][1] > 0) {
        return 100 + matrix[0][0] + matrix[1][0];
    } else {
        return matrix[1][0];
    }
}

int main() {
    int M, K;
    cin >> M >> K;
    string s1, s2;
    cin >> s1 >> s2;

    int sum = 0;
    for (int i = 0; i < M*(K+1)-1; i++)
    {
        char c1 = s1[i], c2 = s2[i];
        int idx1, idx2;
        if(c1 == '|') {
            sum += evaluate();
            matrix[0][0] = 0;
            matrix[0][1] = 0;
            matrix[1][0] = 0;
            matrix[1][1] = 0;
        }

        if(c1 == '0') idx1 = 0;
        else idx1 = 1;
        if(c2 == '0') idx2 = 0;
        else idx2 = 1;

        matrix[idx1][idx2]++;
    }
    sum += evaluate();

    cout << sum;

    return 0;
}