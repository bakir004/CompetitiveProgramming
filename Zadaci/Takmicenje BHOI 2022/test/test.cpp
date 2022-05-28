#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> rijeci;
    int smallest = 1000001;
    for (int i = 0; i < n; i++)
    {   
        string rijec;
        cin >> rijec;
        rijeci.push_back(rijec);
        if(rijec.length() < smallest) {
            smallest = rijec.length();
        }
    }
    smallest++;

    bool failed = false;
    int maxLength = -1;
    for (int j = 0; j < smallest; j++)
    {
        char c;
        if(rijeci[0].length() == j) {
            maxLength = j;
            break;
        } else {
            c = rijeci[0][j];
        }
        for (int i = 1; i < rijeci.size(); i++)
        {
            if(rijeci[i][j] != c) {
                failed = true;
                break;
            }
        }
        if(failed) {
            maxLength = j;
            break;
        }
    }
    for (int i = 0; i < rijeci.size(); i++)
    {
        if(rijeci[i].length() == maxLength) {
            maxLength--;
        }
    }
    
    cout << maxLength;
    return 0;
}