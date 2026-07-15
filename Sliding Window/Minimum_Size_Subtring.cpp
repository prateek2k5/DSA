#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool sahi(vector<int> have, vector<int> need) {
        for (int i = 0; i < 256; i++) {
            if (have[i] < need[i]) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> have(256, 0);
        vector<int> need(256, 0);
        if (n < m) {
            return "";
        }
        // Store frequency of characters in t
        for (int i = 0; i < m; i++) {
            need[t[i]]++;
        }
        int low = 0;
        int res = INT_MAX;
        int start = -1;
        for (int high = 0; high < n; high++) {
            have[s[high]]++;
            while (sahi(have, need)) {
                int len = high - low + 1;
                if (res > len) {
                    res = len;
                    start = low;
                }
                have[s[low]]--;
                low++;
            }
        }
        if (res == INT_MAX) {
            return "";
        }
        return s.substr(start, res);
    }
};

int main() {
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;
    Solution obj;
    string ans = obj.minWindow(s, t);
    cout << "Minimum Window Substring = " << ans << endl;
    return 0;
}