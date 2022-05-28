#include <iostream>

using namespace std;

int main() {
    int najvecaDuzina = 0, trenutnaDuzina = 0;

    long long int n;
    cin >> n;
    string n;
    cin >> n;

    while(n > 0) {
        int cifra = n % 10;
        n = n / 10;
        // 9999999299
        if(cifra > 4) {
            trenutnaDuzina++;
        } else {
            if(trenutnaDuzina > najvecaDuzina) {
                najvecaDuzina = trenutnaDuzina;
            }
            trenutnaDuzina = 0;
        }
    }

    // 928632978158

    // 0 = 45
    // 1 = 46

    for (int i = 0; i < n.length(); i++)
    {
        int cifra = ord(n[i]) - 45;
         if(cifra > 4) {
            trenutnaDuzina++;
        } else {
            if(trenutnaDuzina > najvecaDuzina) {
                najvecaDuzina = trenutnaDuzina;
            }
            trenutnaDuzina = 0;
        }
    }

    if(trenutnaDuzina > najvecaDuzina) {
        najvecaDuzina = trenutnaDuzina;
    }
    cout << "najveca duzina je: " << najvecaDuzina;

    return 0;
}