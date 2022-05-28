#include <iostream>
#include <string>
#include <utility>
#include <cmath>

using namespace std;

void getDamageAndRadius(string spellType, int lvl, int &damage, int &radius) {
    if (spellType == "fire") {
        damage = 200;
        switch(lvl) {
            case 1:
                radius = 20;
                break;
            case 2:
                radius = 30;
                break;
            case 3:
                radius = 50;
                break;
        }
    }
    else if (spellType == "water") {
        damage = 300;
        switch(lvl) {
            case 1:
                radius = 10;
                break;
            case 2:
                radius = 25;
                break;
            case 3:
                radius = 40;
                break;
        }
    }
    else if (spellType == "earth") {
        damage = 400;
        switch(lvl) {
            case 1:
                radius = 25;
                break;
            case 2:
                radius = 55;
                break;
            case 3:
                radius = 70;
                break;
        }
    }
    else if (spellType == "air") {
        damage = 100;
        switch(lvl) {
            case 1:
                radius = 18;
                break;
            case 2:
                radius = 38;
                break;
            case 3:
                radius = 60;
                break;
        }
    }
}

void solve() {
    // rect properties
    int w, h, x0, y0;
    // spell properties
    int cx, cy, N, damage, radius;
    string spellType;

    cin >> w >> h >> x0 >> y0;
    cin >> spellType >> N >> cx >> cy;

    getDamageAndRadius(spellType, N, damage, radius);

    pair<int, int> centerOfRect;
    // x0 i y0 su donji lijevi cosak pravougaonika, 
    // pa je centar pola sirine u desno, i pola visine prema gore
    centerOfRect = make_pair(w/2 + x0, h/2 + y0);

    float distance = sqrt((x0 - cx) * (x0 - cx) + (y0 - cy) * (y0 - cy));
    if(distance <= radius)
        cout << damage << endl << endl;
    else
        cout << 0 << endl << endl;
}

int main()  {
    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cout << endl;
        solve();
    }
}

