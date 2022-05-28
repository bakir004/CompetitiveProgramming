#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> grad;

void init(int N, int T) {
    vector<int> _grad(N, 0);
    grad = _grad;
}

void oblak(int A, int B, int S) {
    for (int i = A; i <= B; i++) {
        grad[i] += S;
    }
}

void vjetar(int A, int B) {
    int arSredina, suma = 0;
    for (int i = A; i <= B; i++) {
        suma += grad[i];
    }
    arSredina = suma / (B - A + 1);
    for (int i = A; i <= B; i++) {
        grad[i] = arSredina;
    }
}

long long sum(int A, int B) {
    long long suma = 0;
    for (int i = A; i <= B; i++) {
        suma += grad[i];
    }
    return suma;
}

int main() {
    init(5, 1);
    oblak(2, 4, 5);
    oblak(1, 3, 7);
    cout << sum(1, 3) << "\n";
    cout << sum(3, 4) << "\n";
    vjetar(3, 4);
    cout << sum(3, 4) << "\n";
    vjetar(0, 2);
    cout << sum(0, 2) << "\n";
    cout << sum(0, 0) << "\n";
    cout << sum(1, 1) << "\n";
    oblak(0, 4, 7);
    vjetar(4, 4);
    return 0;
}