#include <iostream>
#include <fstream>

using namespace std;

// 9180

int main() {
    fstream fileIn;
    fstream fileOut;
    string rijec;
    fileIn.open("C:\\Users\\pc\\Desktop\\bax\\programiranje\\Bosnjacka-Zadaci-master\\Bosnjacka-Zadaci\\Dopuni.ba\\rjecnik.txt", ios::in);
    fileOut.open("C:\\Users\\pc\\Desktop\\bax\\programiranje\\Bosnjacka-Zadaci-master\\Bosnjacka-Zadaci\\Dopuni.ba\\rjecnik-vol-4.txt", ios::out);

    string abeceda[] = {"A", "B", "C", "Č", "Ć", "D", "Đ", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "R", "S", "Š", "T", "U", "V", "Z", "Ž"};
    string trazenoPrvoSlovo;
    int indexSlova = 0;
    string sljedeceSlovo = abeceda[indexSlova];
    while(fileIn >> rijec) {
        if(rijec == sljedeceSlovo) {
            trazenoPrvoSlovo = sljedeceSlovo;
            indexSlova++;
            sljedeceSlovo = abeceda[indexSlova];
        }
        if(toupper(rijec[0]) == trazenoPrvoSlovo[0] 
            && rijec[rijec.length() - 1] != '.' 
            && rijec[rijec.length() - 1] != ',' 
            && rijec[rijec.length() - 1] != ';' 
            && rijec[rijec.length() - 1] != ':'
            && rijec[rijec.length() - 1] != '-'
            && rijec[rijec.length() - 1] != '/'
            && rijec[rijec.length() - 1] != '2'
            && rijec[rijec.length() - 1] != '3'
            && rijec[rijec.length() - 1] != '\\') {
            if(rijec[rijec.length() - 1] == '!' || rijec[rijec.length() - 1] == '1') {
                rijec.pop_back();
            }
            string rijec1 = "", rijec2 = "";
            if(rijec.find('/') != string::npos) {
                bool nasoKosu = false;
                for (int i = 0; i < rijec.length(); i++)
                {
                    if(rijec[i] == '/') {
                        nasoKosu = true;
                        continue;
                    }

                    if(!nasoKosu) 
                        rijec1+=rijec[i];
                    else
                        rijec2+=rijec[i];
                }
            } else if(rijec.find('(') != string::npos) {
                bool nasoZagradu = false;
                for (int i = 0; i < rijec.length(); i++) {
                    if(rijec[i] == '(') {
                        nasoZagradu = true;
                        continue;
                    } else if(rijec[i] == ')') {
                        nasoZagradu = false;
                        continue;
                    }
                    if(!nasoZagradu) {
                        rijec1 += rijec[i];
                        rijec2 += rijec[i];
                    } else {
                        rijec2 += rijec[i];
                    }
                }
            }

            if(rijec1 != "" && rijec2 != "") {
                if(rijec1 != rijec2) {
                    fileOut << rijec1 << "\n";
                    fileOut << rijec2 << "\n";
                } else {
                    fileOut << rijec2 << "\n";
                }
            } else {
                fileOut << rijec << "\n";
            }
        }
        if(sljedeceSlovo == "[") {
            break;
        }
    }

    return 0;
}
