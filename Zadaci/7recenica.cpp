// STATUS: zavrsen
// IZVOR: KTOS-2016

#include <iostream>
#include <vector>

using namespace std;

void capitalizeWords(string &sentence) {
    if((int)sentence[0] >= 97 && (int)sentence[0] <= 122) {
        sentence[0] -= 32;
    }
    for (int i = 1; i < sentence.length(); i++) {
        if(sentence[i - 1] == ' ' && (int)sentence[i] >= 97 && (int)sentence[i] <= 122) {
            sentence[i] -= 32;
        }
    }
}

void replaceWordWithMostA(string &sentence) {
    string wordWithMostA;
    string word = "";
    int mostA = 0, currentA = 0;
    int index, wordLength;
    sentence += ' ';

    for (int i = 0; i < sentence.length(); i++) {
        if(sentence[i] == ' ') {
            if(currentA > mostA) {
                mostA = currentA;
                wordWithMostA = word;
                index = i - word.length();
                wordLength = word.length();
            }
            word = "";
            currentA = 0;
        } else {
            word += sentence[i];
            if(sentence[i] == 'A' || sentence[i] == 'a') {
                currentA++;
            }
        }
    }
    string newSentence = "";
    for (int i = 0; i < sentence.length(); i++) {
        if(i == index) {
            newSentence += "OVDJE";
            i += wordLength - 1;
        } else {
            newSentence += sentence[i];
        }
    }
    sentence = newSentence;
}

void shortenWords(string &sentence) {
    string word = "";
    string newSentence = "";
    sentence += ' ';

    for (int i = 0; i < sentence.length(); i++) {
        if(sentence[i] == ' ') {
            if(word.length() > 9) {
                newSentence += word.substr(0, 3) + '.' + ' ';
            } else {
                newSentence += word + " ";
            }
            word = "";
        } else {
            word += sentence[i];
        }
    }
    sentence = newSentence;
}

int main() {
    string sentence = "Dobro dosli na kantonalno takmicenje iz informatike u Sarajevu.";

    // getline(cin, sentence);

    capitalizeWords(sentence);
    replaceWordWithMostA(sentence);
    shortenWords(sentence);

    cout << sentence;
}