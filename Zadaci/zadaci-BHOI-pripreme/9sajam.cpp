#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <deque>

using namespace std;

int countUnique(vector<int> nums) {
    map<int, int> numbers;
    vector<int> res;

    int left = 0, right = 0;
    deque<int> temp;
    while(left != nums.size() && right != nums.size()) {
        temp.push_back(nums[right]);
        numbers[nums[right]]++;
        bool flag = true;
        for(auto field : numbers) {
            if(field.second <= 0) {
                flag = false;
            }
        }
        if(flag) {
            res.push_back(temp.size());
            left++;
            temp.pop_front();
        } else {
            right++;
        }
    }
    

    

    return *max_element(res.begin(), res.end());
}

int main() {
    int N, K, M;
    int p, v;
    fstream file;
    vector<int> nums;
    vector<int> res;

    file.open("sajam.txt", ios::in);
    file >> N >> K >> M;

    for (int i = 0; i < N; i++) {
        int num;
        file >> num;
        nums.push_back(num);
    }

    for (int i = 0; i < M; i++) {
        int prompt;
        file >> prompt;
        if(prompt == 1) {
            int pos, num;
            file >> pos >> num;
            nums[pos - 1] = num;
        } else {
            res.push_back(countUnique(nums));
        }
    }

    file.close();

    for (int i = 0; i < res.size(); i++){
        cout << res[i] << "\n";
    }
    
    


    return 0;
}

// djelivi sa 8, banane, sajam, velikaana