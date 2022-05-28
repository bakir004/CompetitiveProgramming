// STATUS: zavrsen
// IZVOR: BHOI

#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long int n, k;
    int counter = 0, kCounter = 1;

    cin >> n >> k;
    long long int sumOfKAdditions = k * (k + 1) / 2;
    if(n > sumOfKAdditions) {
        n = n % sumOfKAdditions;
        counter += k * n/sumOfKAdditions;
    } 

    while(n > 0) {
        n -= kCounter;
        kCounter++;
        counter++;
    }
    cout << counter;

    return 0;
}