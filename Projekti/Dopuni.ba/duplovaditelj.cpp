#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
    fstream fileIn;
    fstream fileOut;
    string rijec;
    fileIn.open("C:\\Users\\pc\\Desktop\\bax\\programiranje\\Bosnjacka-Zadaci-master\\Bosnjacka-Zadaci\\Dopuni.ba\\rjecnik-vol-4.txt", ios::in);
    fileOut.open("C:\\Users\\pc\\Desktop\\bax\\programiranje\\Bosnjacka-Zadaci-master\\Bosnjacka-Zadaci\\Dopuni.ba\\rjecnik-vol-5.txt", ios::out);

    map<string, int> rijeci;
    while(fileIn >> rijec) {
        rijeci[rijec]++;
    }

    for(auto par : rijeci) {
        string rijec = par.first;
        // if(rijec.find('\'') != string::npos) {
        //     string novi = "";
        //     for (int i = 0; i < rijec.length(); i++)
        //     {
        //         if(rijec[i] != '\'') {
        //             novi += rijec[i];
        //         }
        //     }
        //     rijec = novi;
        // }
        if(rijec.length() > 1 
            && rijec[rijec.length() - 1] != '.' 
            && rijec[rijec.length() - 1] != ',' 
            && rijec[rijec.length() - 1] != ';' 
            && rijec[rijec.length() - 1] != ':'
            && rijec[rijec.length() - 1] != '-'
            && rijec[rijec.length() - 1] != '\\')
                fileOut << rijec << "\n";
    }

    return 0;
}
