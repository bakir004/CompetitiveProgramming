// Osvojeno bodova: 10/100
// Tacnih testcase-ova: 16/26

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits>

using namespace std;

struct Position {
    int x;
    int y;

    Position(int _x, int _y)  {
        x = _x;
        y = _y;
    }
};

struct Child {
    int xPos;
    int yPos;
    int xThrow;
    int yThrow;

    Child() {
        xPos = 0;
        yPos = 0;
        xThrow = 0;
        yThrow = 0;
    }

    Child(int xP, int yP, int xT, int yT) {
        xPos = xP;
        yPos = yP;
        xThrow = xT;
        yThrow = yT;
    }
};

int getIdOfClosestChild(map<int, Child> children, Position dogPos) {
    int closestChildId;
    int minDistance;
    map<int, Child> closestChildren;
    for (auto childItem : children) {
        int diff = 0;
        Child child = childItem.second;
        diff = abs(child.xPos - dogPos.x) + abs(child.yPos - dogPos.y);
        if(diff < minDistance) {
            minDistance = diff;
        }
    }
    for (auto childItem : children) {
        int diff = 0;
        int id = childItem.first;
        Child child = childItem.second;
        diff = abs(child.xPos - dogPos.x) + abs(child.yPos - dogPos.y);
        if(diff == minDistance) {
            closestChildren.emplace(id, child);
        }
    }
    Child minChild = Child(1000001, 1000001, 1000001, 1000001);
    for (auto child : closestChildren) {
        Child currentChild = child.second;
        if(currentChild.xPos < minChild.xPos) {
            minChild = currentChild;
            closestChildId = child.first;
        } else if(currentChild.xPos == minChild.xPos) {
            if(currentChild.yPos < minChild.yPos) {
                minChild = currentChild;
                closestChildId = child.first;
            }
        }
    }

    return closestChildId;
}

int main() {
    int x, y;
    int xDog, yDog;
    int N;
    map<int, Child> children;

    cin >> x >> y;
    cin >> xDog >> yDog;
    cin >> N;
    Position dogPos = Position(xDog, yDog);

    for (int i = 0; i < N; i++) {
        int xChild, yChild, xThrow, yThrow;
        cin >> xChild >> yChild >> xThrow >> yThrow;
        children.emplace(i, Child(xChild, yChild, xThrow, yThrow));
    }
    vector<bool> visited(N, false);

    while(true) {
        int closestChildId = getIdOfClosestChild(children, dogPos);
        if(visited[closestChildId]) {
            int numOfVisitedChildren = 0;
            for (int i = 0; i < visited.size(); i++) {
                if(visited[i]) {
                    numOfVisitedChildren++;
                }
            }
            cout << numOfVisitedChildren;
            break;
        } else {
            dogPos = Position(children[closestChildId].xThrow, children[closestChildId].yThrow);
            visited[closestChildId] = true;
        }
    }

    return 0;
}



