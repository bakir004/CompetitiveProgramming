#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

int main() {
    fstream json;
    string rijec;
    json.open("C:\\Users\\pc\\Desktop\\bax\\programiranje\\Bosnjacka-Zadaci-master\\Bosnjacka-Zadaci\\Dopuni.ba\\rjecnik-abecedno-json-vol-1.txt", ios::out);

    string abeceda[] = {"A", "B", "C", "Č", "Ć", "D", "Đ", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "R", "S", "Š", "T", "U", "V", "Z", "Ž"};
    json << "{";
    
    for (int i = 0; i < sizeof(abeceda)/sizeof(abeceda[0]); i++)
    {
        json << "\"" << abeceda[i] << "\": [";

        fstream fileIn;
        fileIn.open("C:\\Users\\pc\\Desktop\\bax\\programiranje\\Bosnjacka-Zadaci-master\\Bosnjacka-Zadaci\\Dopuni.ba\\rjecnik-vol-5.txt", ios::in);
        while(fileIn >> rijec) {
            if(toupper(rijec[0]) == (int)abeceda[i][0]) {
                json << "\"" << rijec << "\",";
            }
        }
        json << "],\n";
        fileIn.close();
    }

    json << "}";
    
    

    return 0;
}
