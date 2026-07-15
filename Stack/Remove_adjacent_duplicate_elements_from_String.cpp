// Example 1:
// Input: s = "abbaca"
// Output: "ca"
// Explanation: 
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

// Example 2:
// Input: s = "azxxzy"
// Output: "ay"

#include<bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans = "";
        int n = s.length();
        // String ko traverse karo
        for (int i = 0; i < n; i++) {
            // Agar current character top ke equal hai to remove karo
            if (!st.empty() && st.top() == s[i]) {
                st.pop();
            }
            else {
                // Warna stack me push karo
                st.push(s[i]);
            }
        }
        // Stack ko string me convert karo
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        // Stack reverse order me answer deta hai
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    Solution obj;
    string ans = obj.removeDuplicates(s);
    cout << "Final String = " << ans << endl;
    return 0;
}