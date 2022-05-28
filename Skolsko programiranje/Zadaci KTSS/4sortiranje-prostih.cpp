// STATUS: zavrsen
// IZVOR: KTOS-2015

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(int num){
    for (int i = 2; i < sqrt(num); i++)
    {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;

    cin >> n;

    vector<int> numbers;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        numbers.push_back(num);
    }
    vector<int> primes;
    vector<int> nonPrimes;
    for (int i = 0; i < numbers.size(); i++)
    {
        if(isPrime(numbers[i])) {
            primes.push_back(numbers[i]);
        } else {
            nonPrimes.push_back(numbers[i]);
        }
    }

    auto ascending = [](int a, int b){ return a < b; };
    auto descending = [](int a, int b){ return b < a; };

    sort(primes.begin(), primes.end(), descending);
    sort(nonPrimes.begin(), nonPrimes.end(), ascending);

    for (int i = 0; i < nonPrimes.size(); i++)
    {
        primes.push_back(nonPrimes[i]);
    }
    
    for (int i = 0; i < primes.size(); i++)
    {
        cout << primes[i] << " ";
    }
}