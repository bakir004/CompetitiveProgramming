// STATUS: zavrsen
// IZVOR: KTOS-2015

#include <iostream>

using namespace std;

void reverseString(string &str) {
    for (int i = 0; i < str.length() / 2; i++)
    {
        char temp = str[i];
        str[i] = str[str.length() - 1 - i];
        str[str.length() - 1 - i] = temp;
    }
}

string intToBinary(int num) {
    string binaryNumber = "";
    while(num >= 1) {
        if(num % 2 == 0) {
            binaryNumber += "0";
        } else {
            binaryNumber += "1";
        }
        num /= 2;
    }
    while(binaryNumber.length() < 5) {
        binaryNumber += "0";
    }
    reverseString(binaryNumber);
    return binaryNumber;
}

string charToBinary(char letter) {
    string binaryLetter = "";
    int num;
    if((int)letter >= 65 && (int)letter <= 90) {
        num = (int)letter - 64;
        binaryLetter += "10";
    } else if ((int)letter >= 97 && (int)letter <= 122) {
        num = (int)letter - 96;
        binaryLetter += "11";
    }
    binaryLetter += intToBinary(num);
    return binaryLetter;
}

string charToUnary(char letter) {
    string binary = charToBinary(letter);
    string unary = "";
    int counter = 0;
    char lastChar;

    lastChar = binary[0];
    if(lastChar == '0') {
        unary += "00 0";
    } else {
        unary += "0 0";
    }
    for (int i = 1; i < binary.length(); i++)
    {
        lastChar = binary[i - 1];
        if(lastChar == binary[i]) {
            unary += "0";
        } else if(lastChar == '0' && binary[i] == '1') {
            unary += " 0 0";
        } else if(lastChar == '1' && binary[i] == '0') {
            unary += " 00 0";
        }
    }
    return unary;
}

void solve(string str) {
    for (int i = 0; i < str.length(); i++)
    {
        cout << charToUnary(str[i]) << " ";
    }
}

int main() {
    string inputString = "Ob";
    // cin >> inputString;

    solve(inputString);
    
}