#include<bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int low = 0;
        int res = INT_MIN;
        int n = s.size();
        for (int high = 0; high < n; high++) {
            hash[s[high]]++;
            int k = high - low + 1;
            while (hash.size() < k) {
                char ch = s[low];
                hash[ch]--;
                if (hash[ch] == 0) {
                    hash.erase(ch);
                }
                low++;
                k = high - low + 1;
            }
            int len = high - low + 1;
            res = max(res, len);
        }
        return res;
    }
};

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    Solution obj;
    int ans = obj.lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters = "
         << ans << endl;
    return 0;
}