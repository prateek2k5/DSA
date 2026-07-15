// Example 1:
// Input: s = "abcd", k = 2
// Output: "abcd"
// Explanation: There's nothing to delete.

// Example 2:
// Input: s = "deeedbbcccbdaa", k = 3
// Output: "aa"
// Explanation: 
// First delete "eee" and "ccc", get "ddbbbdaa"
// Then delete "bbb", get "dddaa"
// Finally delete "ddd", get "aa"

// Example 3:
// Input: s = "pbbcggttciiippooaais", k = 2
// Output: "ps"

#include <bits/stdc++.h>
#include <stack>
using namespace std;

string removeDuplicates(string s, int k) {
    int n = s.size();
    // Stack me pair store hoga:
    // first  -> character
    // second -> us character ka continuous count
    stack<pair<char, int>> st;
    // String ke har character ko traverse karenge
    for (int i = 0; i < n; i++) {
        char c = s[i];
        // Agar stack empty hai
        // YA current character stack ke top character se different hai
        if (st.empty() || st.top().first != c) {
            // New character ko count 1 ke saath push karo
            st.push({c, 1});
        }
        // Agar current character stack ke top ke same hai
        else {
            // Us character ka count increase karo
            st.top().second++;
        }
        // Agar same character ka count k ho gaya
        // matlab k adjacent duplicates mil gaye
        if (st.top().second == k) {
            // Pura group stack se remove kar do
            st.pop();
        }
    }
    // Final answer store karne ke liye
    string res = "";
    // Stack ke saare remaining characters ko nikalo
    while (!st.empty()) {
        // Top pair ko p me store karo
        pair<char, int> p = st.top();
        // Stack se pair remove karo
        st.pop();
        // Character ko uske count ke according
        // result string me add karo
        while (p.second--) {
            res += p.first;
        }
    }

    // Stack LIFO follow karta hai
    // isliye result reverse order me bana hai
    reverse(res.begin(), res.end());
    // Final string return karo
    return res;
}

int main() {
    string s;
    int k;
    // User se string input lena
    cout << "Enter string: ";
    cin >> s;
    // k ki value input lena
    cout << "Enter value of k: ";
    cin >> k;
    // Function call karke answer store karna
    string result = removeDuplicates(s, k);
    // Final answer print karna
    cout << "String after removing duplicates: " << result << endl;
    return 0;
}