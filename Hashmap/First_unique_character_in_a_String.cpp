// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

// Example 1:
// Input: s = "leetcode"
// Output: 0
// Explanation:
// The character 'l' at index 0 is the first character that does not occur at any other index.

// Example 2:
// Input: s = "loveleetcode"
// Output: 2

// Example 3:
// Input: s = "aabb"
// Output: -1

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int firstUniqChar(string s) {
    // Har character aur uski frequency store karne ke liye hashmap
    unordered_map<char, int> mp;
    // String ka size store kar rahe hain
    int n = s.size();
    int i;
    // Hashmap create kar rahe hain
    // Har character ki frequency count karenge
    for (i = 0; i < n; i++) {
        // Current character ki frequency increase karo
        mp[s[i]]++;
    }

    // String ko dobara traverse kar rahe hain
    // First unique character find karne ke liye
    for (i = 0; i < n; i++) {
        // Agar character ki frequency 1 hai
        // Matlab ye character unique hai
        if (mp[s[i]] == 1) {
            // First unique character ka index return karo
            return i;
        }
    }
    // Agar koi unique character nahi mila
    // To -1 return karo
    return -1;
}

int main() {
    // Input string store karne ke liye
    string s;
    // User se string input lena
    cout << "Enter the string: ";
    cin >> s;
    // Function call karke result store karna
    int result = firstUniqChar(s);
    // Result display karna
    cout << "First Unique Character Index: " << result << endl;
    return 0;
}