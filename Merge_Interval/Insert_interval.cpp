// Example 1:
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]

// Example 2:
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        // Sort intervals according to starting time
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        // Take the first interval as the current interval
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];
        for (int i = 1; i < n; i++) {
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];
            // If intervals overlap, merge them
            if (end1 >= start2) {
                end1 = max(end1, end2);
                continue;
            }
            // No overlap, store current interval
            res.push_back({start1, end1});
            // Start a new interval
            start1 = start2;
            end1 = end2;
        }
        // Store the last merged interval
        res.push_back({start1, end1});
        return res;
    }
};

int main() {
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter start and end of each interval:\n";
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }
    vector<int> newInterval(2);
    cout << "Enter new interval: ";
    cin >> newInterval[0] >> newInterval[1];
    Solution obj;
    vector<vector<int>> ans = obj.insert(intervals, newInterval);
    cout << "\nIntervals after insertion:\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[" << ans[i][0] << ", " << ans[i][1] << "] ";
    }
    cout << endl;
    return 0;
}