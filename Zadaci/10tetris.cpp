// STATUS: zavrsen
// IZVOR: KTSS-2019

#include <iostream>
#include <vector>

using namespace std;
//svaki vektor u ovom vektoru sadrzi parove koji
//predstavljaju kretanje relativnih
//koordinata (u odnosu na kursor) od pocetka do kraja svakog od
//respektivnih oblika

vector<vector<pair<int,int>>> oblici={
    {{0,0},{0,-1},{0,-2},{1,-2},{-2,-2}},   //A
    {{0,0},{1,0},{2,0},{2,1},{2,2}},        //B
    {{0,0},{0,1},{0,2},{-1,2},{-2,2}},      //C
    {{0,0},{-1,0},{-2,0},{-2,-1},{-2,-2}},  //D
    {{0,0},{1,0},{2,0}},                    //E
    {{0,0},{0,1},{0,2}}                     //F
    };
pair<int,int> cursor={0,299}; //donji lijevi cosak je pocetak

vector<vector<char>> koordinatniSistem(300,vector<char>(300,'-'));

int maksX=0;
int maksY=0;
bool crtaj(char slovo){
    int koji=slovo-'A'; //pretvori u 0 do 5
    int noviX,noviY;
    for(int i=0;i<oblici[koji].size();i++){ //za trenutni oblik provjeri hoce li izaci van bounds ili koliziju dozivjeti
        noviX=cursor.first+oblici[koji][i].first;
        noviY=cursor.second-oblici[koji][i].second;
        if((koordinatniSistem[noviY][noviX]=='*'&&i!=0)||noviX<0||noviY>300){
            return false;
        }
    }


    for(int i=0;i<oblici[koji].size();i++){

        noviX=cursor.first+oblici[koji][i].first;
        noviY=cursor.second-oblici[koji][i].second;

        koordinatniSistem[noviY][noviX]='*';    //postavi * umjesto - svugdje na putanji oblika

        if(noviX>maksX){
            maksX++;
        }
        if(299-noviY>maksY){
            maksY++;
        }
    }
    cursor.first=noviX; //update cursor pos
    cursor.second=noviY;



    return true;
}
void isprintaj(){
    if(maksY==0&&maksX==0){
        return;
    }
    for(int i=299-maksY;i<300;i++){
    for(int j=0;j<=maksX;j++){
        cout<<koordinatniSistem[i][j];
    }
            if(i!=299){
            cout<<endl;
            }

    }
}
int main()
{
    string ulaz;
    getline(cin,ulaz);
    for(int i=0; i<ulaz.length(); i++) {
        if(crtaj(ulaz[i])==false) break;
    }

    isprintaj();
    return 0;

}
