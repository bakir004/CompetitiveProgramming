#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    vector<char> s;
    cin >> str;

    // for (int i = 0; i < n; i++) {
    //     char c = str[i];
    //     if(c == '(' || c == '[' || c == '{' || c == '<') {
    //         s.push_back(c);
    //         continue;
    //     }

    //     if((c == ')' && s[s.size() - 1] == '(') || (c == ']' && s[s.size() - 1] == '[') || (c == '}' && s[s.size() - 1] == '{') || (c == '>' && s[s.size() - 1] == '<')) {
    //         s.pop_back();
    //         continue;
    //     } else {
    //         cout << "pogresan";
    //         return 0;
    //     }
    // }
    // cout << "dobar";

    vector<char> st;
    vector<char> opening = {'<', '(', '[', '{'};
    vector<char> closing = {'>', ')', ']', '}'};

    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if(find(opening.begin(), opening.end(), c) != opening.end()) {
            st.push_back(c);
            continue;
        } else {
            int index = find(closing.begin(), closing.end(), c) - closing.begin();
            char closingBracket = opening[index];
            if(st[st.size() - 1] == closingBracket) {
                st.pop_back();
                continue;
            } else {
                cout << "pogresan";
                return 0;
            }
        }
    }
    cout << "dobar";
    

    return 0;
}