#include<bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char, int> hash;
        int low = 0;
        int res = -1;
        int n = s.size();
        for (int high = 0; high < n; high++) {
            hash[s[high]]++;
            while (hash.size() > k) {
                char ch = s[low];
                hash[ch]--;
                if (hash[ch] == 0) {
                    hash.erase(ch);
                }
                low++;
            }
            if (hash.size() == k) {
                int len = high - low + 1;
                res = max(res, len);
            }
        }
        return res;
    }
};

int main() {
    string s;
    int k;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter value of k: ";
    cin >> k;
    Solution obj;
    int ans = obj.longestKSubstr(s, k);
    cout << "Length of longest substring with " << k
         << " distinct characters = " << ans << endl;
    return 0;
}