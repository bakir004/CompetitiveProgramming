// Osvojeno bodova: 70/100
// Tacnih testcase-ova: 28/29

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int M;
    short N, T;

    cin >> N >> M >> T;

    int A[N], B[N];

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        A[i] = num;
    }
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        B[i] = num;
    }
    set<int> setC;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        setC.insert(num);
    }

    int counter = 0;
    if(T == 0) {
        for (int i = 0; i < N; i++) {
            if(B[i] >= A[i]) {
                int diff = B[i] - A[i];
                if(setC.find(diff) != setC.end()) {
                    counter++;
                }
            }
        }
    } else {
        vector<bool> doneB(N, false);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++){
                if(!doneB[j] && B[j] >= A[i]) {
                    int diff = B[j] - A[i];
                    if(binary_search(setC.begin(), setC.end(), diff)) {
                        counter++;
                        doneB[j] = true;
                    }
                }
            }
        }
    }
    cout << counter;
    

    return 0;
}