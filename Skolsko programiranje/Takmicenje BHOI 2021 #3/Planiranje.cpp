#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Interval {
    int id;
    int start;
    int end;
    int cost;

    Interval(int i, int a, int b, int c) {
        id = i;
        start = a;
        end = b;
        cost = c;
    }
    bool operator<(const Interval c) {
        return start < c.start;
    }
};

int main() {
    vector<Interval> intervals;
    map<Interval, vector<Interval>> overlapping;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        intervals.push_back(Interval(i,a,b,c));
    }

    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < intervals.size(); i++) {
        Interval curr = intervals[i];
        for (int j = 0; j < intervals.size(); j++) {
            if(i != j) {
                Interval second = intervals[j];
                if(!(curr.start > second.end && second.start < curr.end) || curr.end >= second.start || second.end >= curr.start) {
                    overlapping[curr].push_back(second);
                }
            }
        }
    }
    

    int maxCost, totalCost = 0;
    for (int i = 0; i < n; i++) {
        
        
        
    }
    
    



    return 0;
}