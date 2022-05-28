// STATUS: zavrsen
// IZVOR: KTOS-2015

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Lokvanj {
    float x, y, r, broj;
    bool visited;

    Lokvanj(float x, float y, float r, float broj, bool visited){
        x = x;
        y = y;
        r = r;
        broj = broj;
        visited = visited;
    }
};

float udaljenost2lokvanja(Lokvanj lok1, Lokvanj lok2) {
    return sqrt(pow(lok1.x - lok2.x, 2) + pow(lok1.y - lok2.y, 2));
}

vector<Lokvanj> pronadjiNajblizeLokvanje(Lokvanj start, vector<Lokvanj> lokvanji) {
    vector<Lokvanj> najblizi = {};
    float udaljenost = 0.1;
    for (int i = 0; i < lokvanji.size(); i++)
    {
        if(udaljenost2lokvanja(start, lokvanji[i]) < start.r + lokvanji[i].r + udaljenost && lokvanji[i].broj != start.broj && !lokvanji[i].visited) {
            najblizi.push_back(lokvanji[i]);
        }
    }
    return najblizi;
}

bool startSkakanje(Lokvanj pocetniLokvanj, vector<Lokvanj> lokvanji) {
    static vector<int> put;
    static bool nasoKucu = false;
    if(!nasoKucu) {
        // cout << pocetniLokvanj.broj << ", ";
        for (int i = 0; i < lokvanji.size(); i++)
        {
            if(pocetniLokvanj.broj == lokvanji[i].broj) {
                lokvanji[i].visited = true;
            }
        }
        
        vector<Lokvanj> najblizi = pronadjiNajblizeLokvanje(pocetniLokvanj, lokvanji);
        
        if(najblizi.size() <= 0 && pocetniLokvanj.broj == 0) {
            cout << "Frogi nema rucka";
            return false;
        }
        if(najblizi.size() <= 0)
            return false;

        vector<bool> stablaImajuPut(najblizi.size(), false);
        for (int i = 0; i < najblizi.size(); i++) {

            if(najblizi[i].broj == -1) {
                // cout << "naso kucu";
                nasoKucu = true;
                put.push_back(pocetniLokvanj.broj);
                return true;
            }

            bool imaDalje = startSkakanje(najblizi[i], lokvanji);

            stablaImajuPut[i] = imaDalje;
        }
        if(find(stablaImajuPut.begin(), stablaImajuPut.end(), true) == stablaImajuPut.end() && pocetniLokvanj.broj == 0) {
            cout << "Frogi nema rucka";
            return false;
        } else if(find(stablaImajuPut.begin(), stablaImajuPut.end(), true) == stablaImajuPut.end())
            return false;
        else {
            if(pocetniLokvanj.broj == 0) {
                reverse(put.begin(), put.end());
                for (int i = 0; i < put.size(); i++)
                {
                    cout << put[i] << " ";
                }
            } else
                put.push_back(pocetniLokvanj.broj);

            return true;
        }
    }
    return false;
}

int main() {
    pair<float, float> frogi;
    pair<float ,float> kuca;
    vector<Lokvanj> lokvanji;
    int N=1;

    frogi.first=-3;
    frogi.second=-3;

    kuca.first=4;
    kuca.second=2.5;

    // Lokvanj lokvanjPrvi(frogi.first, frogi.second, 0, 0, false);
    // Lokvanj lokvanj1(-2,-2.5,1.2,1, false);
    // Lokvanj lokvanj2(-1,2.5,1,2, false);
    // Lokvanj lokvanj3(-1,-0.5,0.7,3, false);
    // Lokvanj lokvanj4(0.2,-1.8,1.2,4, false);
    // Lokvanj lokvanj5(1.3,-1,1,5, false);
    // Lokvanj lokvanj6(2.3,0.4,1,6, false);
    // Lokvanj lokvanj7(3.8,-1.3,0.8,7, false);
    // Lokvanj lokvanj8(1.8,-1,0.5,8, false);
    // Lokvanj lokvanj9(-2,0.5,0.7,9, false);
    // Lokvanj lokvanj10(3.8,1.8,1,10, false);
    // Lokvanj lokvanjKuca(kuca.first,kuca.second,0,-1, false);

    // lokvanji.push_back(lokvanj1);
    // lokvanji.push_back(lokvanj2);
    // lokvanji.push_back(lokvanj3);
    // lokvanji.push_back(lokvanj4);
    // lokvanji.push_back(lokvanj5);
    // lokvanji.push_back(lokvanj6);
    // lokvanji.push_back(lokvanj7);
    // lokvanji.push_back(lokvanj8);
    // lokvanji.push_back(lokvanj9);
    // lokvanji.push_back(lokvanj10);
    // lokvanji.push_back(lokvanjKuca);
    
    // frogi.first=0;
    // frogi.second=0;

    // kuca.first=2;
    // kuca.second=2;

    // Lokvanj lokvanjPrvi(frogi.first, frogi.second, 0, 0, false);
    // Lokvanj lokvanj1(1,1,0.5,1, false);
    // Lokvanj lokvanj2(1.5,1.5,0.5,2, false);
    // Lokvanj lokvanjKuca(kuca.first, kuca.second, 0, -1, false);

    // lokvanji.push_back(lokvanj1);
    // lokvanji.push_back(lokvanj2);
    // lokvanji.push_back(lokvanjKuca);

    // frogi.first=0;
    // frogi.second=0;

    // kuca.first=2;
    // kuca.second=2;

    // Lokvanj lokvanjPrvi(frogi.first, frogi.second, 0, 0, false);
    // Lokvanj lokvanj1(1,1,0.5,1, false);
    // Lokvanj lokvanj2(0.5,0.5,0.8,2, false);
    // Lokvanj lokvanjKuca(kuca.first, kuca.second, 0, -1, false);

    // lokvanji.push_back(lokvanj1);
    // lokvanji.push_back(lokvanj2);
    // lokvanji.push_back(lokvanjKuca);

    // for (int i = 0; i < N; i++)
    // {
    //     lokvanj.x=1;
    //     lokvanj.y=2;
    //     lokvanj.broj=3;
    //     lokvanj.r=4;
    //     cin >> lokvanj.x >> lokvanj.y >> lokvanj.r;
    //     lokvanj.broj = i + 1;
    //     lokvanji.push_back(lokvanj);
    // }
    // startSkakanje(lokvanjPrvi, lokvanji);


}