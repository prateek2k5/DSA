#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int find(vector<int> a) {
        int maxcnt = -1;
        for (int i = 0; i < 256; i++) {
            maxcnt = max(maxcnt, a[i]);
        }
        return maxcnt;
    }

    int characterReplacement(string s, int k) {
        vector<int> f(256, 0);
        int n = s.size();
        int low = 0;
        int res = INT_MIN;
        for (int high = 0; high < n; high++) {
            f[s[high]]++;
            int len = high - low + 1;
            int maxcnt = find(f);
            int diff = len - maxcnt;
            while (diff > k) {
                f[s[low]]--;
                low++;
                len = high - low + 1;
                maxcnt = find(f);
                diff = len - maxcnt;
            }
            len = high - low + 1;
            res = max(res, len);
        }
        return res;
    }
};

int main() {
    string s;
    int k;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;
    Solution obj;
    int ans = obj.characterReplacement(s, k);
    cout << "Longest length after replacement = " << ans << endl;
    return 0;
}