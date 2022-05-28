#include <iostream>

using namespace std;

int main() {    
    float n;
    cout << "\nUnesite kvadrat prirodnog broja: ";
    // unos
    cin >> n;
    
    // "originalni" je kopija n-a
    float originalni = n;

    for (int i = 0; i < 1000; i++)
    {
        // ovaj sadrzaj se izvrsava 1000 puta
        n = ((originalni / n) + n) / 2.0;
    }
    
    // ispis
    cout << "n nakon 1000 ponavljanja algoritma tezi: " << n << "\n\n";
    
    return 0;
}