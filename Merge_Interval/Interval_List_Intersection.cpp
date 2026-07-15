// Example 1:
// Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
// Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

// Example 2:
// Input: firstList = [[1,3],[5,9]], secondList = []
// Output: []

#include<bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        int n = a.size();
        int m = b.size();
        // Dono lists ko ek sath traverse karo
        while (i < n && j < m) {
            int start1 = a[i][0];
            int end1 = a[i][1];
            int start2 = b[j][0];
            int end2 = b[j][1];
            // Agar overlap hai to intersection store karo
            if (start1 <= start2) {
                if (end1 >= start2) {
                    int s = max(start1, start2);
                    int e = min(end1, end2);
                    res.push_back({s, e});
                }
            }
            else {
                if (end2 >= start1) {
                    int s = max(start1, start2);
                    int e = min(end1, end2);
                    res.push_back({s, e});
                }
            }
            // Jiska interval pehle end ho raha hai uska pointer aage badhao
            if (end1 <= end2)
                i++;
            else
                j++;
        }
        return res;
    }
};

int main() {
    int n, m;
    cout << "Enter number of intervals in first list: ";
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    cout << "Enter first list intervals:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    cout << "Enter number of intervals in second list: ";
    cin >> m;
    vector<vector<int>> b(m, vector<int>(2));
    cout << "Enter second list intervals:\n";
    for (int i = 0; i < m; i++) {
        cin >> b[i][0] >> b[i][1];
    }
    Solution obj;
    vector<vector<int>> ans = obj.intervalIntersection(a, b);
    cout << "\nIntersection Intervals:\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[" << ans[i][0] << ", " << ans[i][1] << "] ";
    }
    cout << endl;
    return 0;
}