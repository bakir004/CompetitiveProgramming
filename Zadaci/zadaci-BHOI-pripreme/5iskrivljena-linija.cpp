#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> nums;

    for (int i = 0; i < 4; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    int minElement = *min_element(nums.begin(), nums.end());
    int maxElement1 = *max_element(nums.begin(), nums.end());
    nums[max_element(nums.begin(), nums.end()) - nums.begin()] = -1;
    int maxElement2 = *max_element(nums.begin(), nums.end());

    cout << minElement * min(maxElement1, maxElement2);

    return 0;
}