#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    fstream json;
    string rijec = "čahurčić";
    json.open("C:\\Users\\pc\\Desktop\\bax\\programiranje\\Bosnjacka-Zadaci-master\\Bosnjacka-Zadaci\\Dopuni.ba\\rjecnik-kombinacije-json-vol-2.txt", ios::out);

    string abeceda[] = {"A", "B", "C", "Č", "Ć", "D", "Đ", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "R", "S", "Š", "T", "U", "V", "Z", "Ž"};
    json << "{";
    int counter = 0;

    for (int i = 0; i < sizeof(abeceda)/sizeof(abeceda[0]); i++)
    {
        for (int j = 0; j < sizeof(abeceda)/sizeof(abeceda[0]); j++)
        {
            for (int k = 0; k < sizeof(abeceda)/sizeof(abeceda[0]); k++)
            {
                counter++;
                if(counter % 100 == 0) {
                    cout << counter << endl;
                }
                string kombinacija = abeceda[i] + abeceda[j] + abeceda[k];
                json << "\"" << kombinacija << "\": [";

                fstream fileIn;
                fileIn.open("C:\\Users\\pc\\Desktop\\bax\\programiranje\\Bosnjacka-Zadaci-master\\Bosnjacka-Zadaci\\Dopuni.ba\\rjecnik-vol-5.txt", ios::in);
                while(fileIn >> rijec) {
                    string novi = "";
                    for (int i = 0; i < rijec.length(); i++) {
                        if(rijec.find("č") == i) {
                            novi+= "Č";
                            novi.pop_back();
                        } else if(rijec.find("ć") == i) {
                            novi+= "Ć";
                            novi.pop_back();
                        }
                        else if(rijec.find("š") == i) {
                            novi+= "Š";
                            novi.pop_back();
                        }
                        else if(rijec.find("đ") == i) {
                            novi+= "Đ";
                            novi.pop_back();
                        }
                        else if(rijec.find("ž") == i) {
                            novi+= "Ž";
                            novi.pop_back();
                        }
                        else novi += toupper(rijec[i]);
                    }
                    
                    if (novi.find(kombinacija) != std::string::npos) {
                        json << "\"" << novi << "\",";
                    }
                }
                json << "],\n";
                fileIn.close();
            }
        }
    }

    json << "}";

    return 0;
}
