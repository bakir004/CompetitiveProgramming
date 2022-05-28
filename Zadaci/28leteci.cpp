// STATUS: zavrsen
// IZVOR: BHOI

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


void pingvin(string input) {
    string slova="ACTG";

    if(input.length()%4!=0) {   //Ako nije djeljivo sa 4 onda nije ok
        cout<<"Neke ptice nikad ne polete";
        return;
    }

    vector<int> histogram(4,0); //Histogram za brojanje
    for(int i=0; i<input.length(); i++) {
        if(input[i]=='A') {
            histogram[0]++;
        } else if(input[i]=='C') {
            histogram[1]++;
        } else if(input[i]=='G') {
            histogram[2]++;
        } else if(input[i]=='T') {
            histogram[3]++;
        }
    }


    int temp=histogram[0];
    bool flag=false;
    for(int i=0; i<histogram.size(); i++) {
        if(temp!=histogram[i]) {
                flag=true;
                break;
        }
    }
    if(!flag) {
        cout<<"Ovo nije pingvin";
        return;
    }

    //banku popunimo sa individualnim karakterima kojih ima po 1/4 str length
    //Svako slovo u mapi ima int kao pridruzenu vrijednost
    //int predstavlja broj ponavljanja tog slova
    int br_slova=input.length()/4;
    map<char,int> banka;
    for(int i=0;i<4;i++){
        banka.emplace(slova[i],br_slova);
    }
    //s lijeve strane idemo kroz nas originalni string i
    //ako nadjemo element koji postoji i u banci, izbacimo ga iz banke
    //kad potrosimo jedno slovo iz banke idemo dalje
    int i;
    for(i=0; i<input.length(); i++) {
        if(banka[input[i]]>0) {
            banka[input[i]]--;
        } else {
            break;
        }
    }
    //s desne strane idemo kroz nas originalni string i
    //ako nadjemo element koji postoji i u banci, izbacimo ga iz banke
    //kad potrosimo jedno slovo iz banke idemo dalje
    int j;
    for(j=input.length()-1; j>=0; j--) {
        if(banka[input[j]]>0) {
            banka[input[j]]--;
        } else {
            break;
        }
    }

    //preostali broj elementaa u banci je ustvari duzina podstringa
    //koji se treba promijeniti
    int rezultat=0;
    for(int i=0;i<4;i++){
        rezultat+=banka[slova[i]];
    }
    cout<<rezultat;
}

int main() {
    string input;
    cin>>input;
    pingvin(input);
    return 0;
}