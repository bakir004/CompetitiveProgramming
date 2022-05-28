#include <iostream>
#include <vector>
#define BIG_INT 1000000007

using namespace std;

struct Interval {
    int L;
    int R;

    Interval(int l, int r) {
        L = l;
        R = r;
    }
};

long long int solve(vector<long long int> array, Interval interval) {
    long long int factor = 1;
    long long int sum = 0;
    for (int i = interval.L - 1; i < interval.R; i++) {
        sum += factor * array[i];
        sum = sum % BIG_INT;
        factor *= 2;
    }
    return sum;
}

int main() {
    int n, q;
    vector<long long int> array;

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        array.push_back(num);
    }
    
    for (int i = 0; i < q; i++) {
        int L,R;
        cin >> L >> R;
        cout << solve(array, Interval(L,R)) << "\n";
    }
    
    

    return 0;
}