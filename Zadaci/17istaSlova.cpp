// STATUS: zavrsen
// IZVOR: KTOS-2017

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void toLower(string &s) {
    for (int i = 0; i < s.length(); i++) {
        if(s[i] >= 65 && s[i] <= 90) {
            s[i] += 32;
        }
    }
}

bool containsSameLetters(string s1, string s2) {
    toLower(s1);
    toLower(s2);

    for (int i = 0; i < s1.size(); i++) {
        if(s2.find(s1[i]) == string::npos) {
            return false;
        }
    }
    for (int i = 0; i < s2.size(); i++) {
        if(s1.find(s2[i]) == string::npos) {
            return false;
        }
    }
    return true;
}

int main() {

    int t;
    cin >> t;

    string str1, str2;
    vector<string> answers;

    for (int i = 0; i < t; i++) {
        cin >> str1;
        cin >> str2;
        if(containsSameLetters(str1, str2)) {
            answers.push_back("DA");
        } else {
            answers.push_back("NE");
        }
    }
    for (int i = 0; i < answers.size(); i++) {
        cout << answers[i] << "\n";
    }
    
    
    return 0;
}