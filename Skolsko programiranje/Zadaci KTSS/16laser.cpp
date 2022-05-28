// STATUS: zavrsen
// IZVOR: KTOS-2017

#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    int width, height;
    Point start, end;
    int bounces = 0;
    int didHitCorner = 0;
    bool flippedX = false, flippedY = false;

    cin >> start.x >> start.y >> end.x >> end.y;
    cin >> width >> height;

    // start.x = 1, start.y = 1, end.x = 7, end.y = 5, width = 7, height = 7;

    Point startEndDiff;
    startEndDiff.x = end.x - start.x;
    startEndDiff.y = end.y - start.y;

    if(startEndDiff.x == 0 || startEndDiff.y == 0) {
        cout << "0 1";
        return 0;
    }

    // ideja sa paralelnim svemirima, kako ih ja zovem
    while(true) {
        end.x += startEndDiff.x;
        end.y += startEndDiff.y;

        if(end.x > width) {
            flippedX = !flippedX;
            end.x -= width;
            bounces++;
        } else if(end.x < 0) {
            flippedX = !flippedX;
            end.x += width;
            bounces++;
        }
        if(end.y > height) {
            flippedY = !flippedY;
            end.y -= height;
            bounces++;
        } else if(end.y < 0) {
            flippedY = !flippedY;
            end.y += height;
            bounces++;
        }

        if((end.x == width && end.y == height) || (end.x == width && end.y == 0) || (end.x == 0 && end.y == 0) || (end.x == 0 && end.y == height)) {
            didHitCorner = -1;
            break;
        }

        if(end.x == start.x && end.y == start.y) {
            if(!flippedX && !flippedY) {
                break;
            }
        }
    }
    cout << didHitCorner << " " << bounces;

    return 0;
}