#include <iostream>
#include <string>

using namespace std;

class Kviz {
    public:
        int ukupniBodovi;
        int sviBodovi;

        void inicijalizacija() {
            // postavljanje varijabli na 0
            ukupniBodovi = 0;
            sviBodovi = 0;
        }

        // funkcija koja pita pitanja, prima pitanje, odgovore, redni broj tacnog odgovora i broj bodova koji nosi
        void pitajPitanje( 
            string pitanje,
            string odgovor1,
            string odgovor2,
            string odgovor3,
            string odgovor4,
            int tacanOdgovor,
            int bodovi
        ) {
            // odgovor je redni broj odgovora koji korisnik unese kasnije
            int odgovor;
            cout << pitanje << " (" << bodovi << ")\n";
            cout << "1. " << odgovor1 << "\n";
            cout << "2. " << odgovor2 << "\n";
            cout << "3. " << odgovor3 << "\n";
            cout << "4. " << odgovor4 << "\n";            
            cout << "Unesite redni broj odgovora (bez tacke): ";
            cin >> odgovor;
            // postavka pitanja tj. sablon
            if(odgovor == tacanOdgovor) {
                ukupniBodovi += bodovi;
                cout << "Odgovor je tacan. Imate " << ukupniBodovi << " bodova.\n";
            } else {
                cout << "Odgovor je netacan. Imate " << ukupniBodovi << " bodova.\n";
            }
            sviBodovi += bodovi;
            // ako korisnik tacno odgovori, dodaju mu se bodovi, u suprotnom ne
        }
};
 
int main()
{
    cout << "\n\n\t\t\t\tAMINOV KVIZ"
         << endl;
    cout << "\n\nPritisnite ENTER da zapocnete "
         << "kviz... " << endl;

    cin.get(); // cekamo da korisnik pritisne enter da nastavimo

    Kviz kviz;
    kviz.inicijalizacija(); // inicijaliziramo kviz tako da postavimo ukupne bodove na 0

    // pocetak kviza, funkcija poziva pitanja
    kviz.pitajPitanje(
        "Koliko Zemljine površine čini voda?",
        "60%", "70%", "75%", "80%",
        2,
        10
    );

    // kopirati i postaviti pitanja

    // u klasi kviz imamo bodove, samo ih ispisemo
    cout << "Kviz je zavrsen, osvojili ste " << kviz.ukupniBodovi << "/" << kviz.sviBodovi << " bodova.";

    //provjera bodova
    if(kviz.ukupniBodovi <= 70) {
        cout << "Nazalost, nemate dovoljno bodova za prolazak u baraz.";
    } else {
        cout << "Cestitam, osvojili ste dovoljno bodova za cevape.";
    }
    
    return 0;
}