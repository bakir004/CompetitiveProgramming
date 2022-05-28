#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if(num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0)
            return false;
    }
    return true;
}

int diagonalDifference(vector<vector<int>> matrix) {
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < matrix.size(); i++) {

        if(isPrime(matrix[i][i]))
            sum1 += matrix[i][i];
    }
    for (int i = 0; i < matrix.size(); i++) {
        int j = matrix.size() - i - 1;

        if(isPrime(matrix[i][j]))
            sum2 += matrix[i][j];
    }

    return abs(sum1 - sum2);
}

int main() {
    for(int i=0;i<=10;i++){
        //prodje kroz svih 11 test slucaja
        string path1="C:\\Users\\Zakir\\Desktop\\Rezultati i testovi skolskog takmicenja 2021\\Z1 testovi za zadatak\\input";
        string path2="C:\\Users\\Zakir\\Desktop\\output";
    if(i==10){
        path1+="10.txt";
        path2+="10.txt";
        } else {
        path1+="0";
        path2+="0";
        path1+=i+'0';
        path2+=i+'0';
        path1+=".txt";
        path2+=".txt";
    }
    fstream file1;
    fstream file2;
    file1.open(path1,ios::in);
    file2.open(path2,ios::out);


//BEGIN UCENIK KOD




//Ovdje ubacite vaš algoritam, zamijeniti cin sa file1, cout sa file2.
//Program će automatski za svaki input.txt napraviti output.txt.
//Nakon toga pokrenuti autotest i vidjeti koliko je outputa dobro a koliko nije.

    int n;

    file1 >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file1 >> matrix[i][j];
        }
    }
    
    file2 << diagonalDifference(matrix);




//END UCENIK KOD



    }
    return 0;
}
