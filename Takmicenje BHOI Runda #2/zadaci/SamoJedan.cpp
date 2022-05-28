#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<int> books;

    cin >> n;

    for (int i = 0; i < 2 * n - 1; i++) {
        int num;
        cin >> num;
        books.push_back(num);
    }

    sort(books.begin(), books.end());

    for (int i = 0; i < books.size(); i+=2) {
        if(books[i] != books[i + 1]) {
            cout << books[i];
            return 0;
        }
    }
    
    return 0;
}