#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long long int, long long int>> rows;
long long int cursorY, cursorX;

long long int solve(long long int _cursorY, long long int _cursorX, long long int endX, long long int endY) {
    long long int totalCost = abs(_cursorY - endY);
    int direction;

    cursorY = _cursorY;
    cursorX = _cursorX;

    while(true) {

        if(cursorY > endY)
            direction = -1;
        else if(cursorY < endY)   
            direction = 1;
        else {
            totalCost += abs(cursorX - endX);
            cursorX = endX;
            return totalCost;
        }

        cursorY += direction;

        pair<long long int, long long int> row = rows[cursorY - 1];
        if(cursorX < row.first) {
            totalCost += row.first - cursorX;
            cursorX = row.first;
        } else if(cursorX > row.second) {
            totalCost += cursorX - row.second;
            cursorX = row.second;
        }
    }
    return totalCost;
}

int main() {
    long long int N, Q;
    cin >> N >> Q;
    
    for (long long int i = 0; i < N; i++)
    {
        long long int begin, end;
        cin >> begin >> end;
        rows.push_back(make_pair(begin, end));
    }

    for (long long int i = 0; i < Q; i++)
    {
        long long int endX, endY;
        cin >> cursorY >> cursorX >> endX >> endY;
        cout << solve(cursorX, cursorY, endX, endY) << endl;
    }
}