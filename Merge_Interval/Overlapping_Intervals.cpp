// Input: n = 4, arr[][] = [[1, 3], [5, 7], [2, 4], [6, 8]]
// Output: true
// Explanation: The intervals [1, 3] and [2, 4] overlap.

// Input: n = 4, arr[][] = [[1, 3], [7, 9], [4, 6], [10, 13]]
// Output: false
// Explanation: No pair of intervals overlap.

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIntersect(vector<vector<int>>& intervals) {
        // Start time ke according sort karo
        sort(intervals.begin(), intervals.end());
        // Pehla interval current interval maan lo
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];
        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];
            // Agar overlap hai to intersection mil gaya
            if (start2 <= end1) {
                return true;
            }
            // Current interval ko update karo
            start1 = start2;
            end1 = max(end1, end2);
        }
        // Koi overlap nahi mila
        return false;
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
    Solution obj;
    if (obj.isIntersect(intervals))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}