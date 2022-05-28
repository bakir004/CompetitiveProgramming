#include <iostream>
#include <vector>

using namespace std; 

bool isSpecialCharacter(char character) {
    if(character == '!' || character == '@' || character == '#' || character == '$' || character == '%' || character == '^' || character == '&' || character == '*' || character == '(' || character == ')' || character == '-' || character == '+') {
        return true;
    }
    return false;
}

bool isUpper(char character) {
    if((int)character >= 65 && (int)character <= 90) {
        return true;
    }
    return false;
}

bool isLower(char character) {
    if((int)character >= 97 && (int)character <= 122) {
        return true;
    }
    return false;
}

bool isNumber(char character) {
    if((int)character >= 45 && (int)character <= 54) {
        return true;
    }
    return false;
}

int minimumNumber(string pw, int length) {
    vector<bool> isValid(4, false);
    for (int i = 0; i < length; i++) {
        if(isLower(pw[i])) {
            isValid[0] = true;
            continue;
        }
        if(isUpper(pw[i])) {
            isValid[1] = true;
            continue;
        }
        if(isSpecialCharacter(pw[i])) {
            isValid[2] = true;
            continue;
        }
        if(isNumber(pw[i])) {
            isValid[3] = true;
            continue;
        }
    }
    int validChecks = 0;
    for (int i = 0; i < isValid.size(); i++) {
        if(isValid[i]) {
            validChecks++;
        }
    }
    int needsChars = 0;
    needsChars += 4 - validChecks;
    if(needsChars + length >= 6) {
        return needsChars;
    } else {
        return 6 - length;
    }

    return -1;
}

int main() {
    int n;
    string pw;

    cin >> n >> pw;

    cout << minimumNumber(pw, n);

    return 0;
}