#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());

    int numsGreaterOrEqualToK = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i] >= k) {
            numsGreaterOrEqualToK++;
        }
    }
    int leftover = arr.size() - numsGreaterOrEqualToK;
    int numOfElementsAllowed = numsGreaterOrEqualToK - 1;

    int numsToAdd = min(leftover, numOfElementsAllowed);

    int finalCount = numsToAdd + ((numsGreaterOrEqualToK * (numsGreaterOrEqualToK + 1)) / 2);

    cout << finalCount;
}