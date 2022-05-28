#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    string s;

    cin >> s;

    int longestPalindrome = -1;
    int indexOfLongestPalindrome = 0;
    int len = s.length();

    if(len % 2 == 0) {
        for (int i = 0; i < len - 1; i++) {
            if(s[i] == s[i + 1]) {
                int left = i;
                int right = i + 1;
                int counter = 2;

                while(left >= 0 && right < len) {
                    left--;
                    right++;
                    if(s[left] == s[right]) {
                        counter+=2;
                    } else {
                        break;
                    }
                }
                if(counter > longestPalindrome) {
                    indexOfLongestPalindrome = i;
                    longestPalindrome = counter;
                }
            } else if(len == 2 && s[i] != s[i + 1]) {
                cout << 1;
                return 0;
            }
        }
    } else {
        for (int i = 0; i < len; i++) {
            int left = i;
            int right = i;
            int counter = 1;

            while(left >= 0 && right < len) {
                left--;
                right++;
                if(s[left] == s[right]) {
                    counter+=2;
                } else {
                    break;
                }
            }
            if(counter > longestPalindrome) {
                indexOfLongestPalindrome = i;
                longestPalindrome = counter;
            }
        }
    }
    int left, right;
    if(len % 2 == 0) {
        left = indexOfLongestPalindrome - 1;
        right = indexOfLongestPalindrome + 2;
    } else {
        left = indexOfLongestPalindrome - 1;
        right = indexOfLongestPalindrome + 1;
    }
    int steps = 0;
    while(left >= 0 || right < len) {
        if(left >= 0 && right < len) {
            if(s[left] != s[right])
                steps+=2;
        } else if(left >= 0) {
            steps++;
        } else if(right < len) {
            steps++;
        } else {
            break;
        }
        left--;
        right++;
    }
    cout << steps;
    return 0;
}