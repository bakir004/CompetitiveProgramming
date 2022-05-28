#include <iostream>

using namespace std;

int main() {
    int dimenzije;
    cin >> dimenzije;
    char smjer;
    cin >> smjer;

    if(smjer == 'D') {
        for (int i = dimenzije - 1; i >= 0; i--)
        {
            for (int j = i; j >= i - dimenzije + 1; j--)
            {
                cout << abs(j) << " ";
            }
            cout << endl;
        }
    } else {
        for (int i = 0; i >= -dimenzije + 1; i--)
        {
            for (int j = i; j <= i + dimenzije - 1; j++)
            {
                cout << abs(j) << " ";
            }
            cout << endl;
        }
    }    

    return 0;
}