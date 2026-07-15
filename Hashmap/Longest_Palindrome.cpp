// Example 1:
// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

// Example 2:
// Input: s = "a"
// Output: 1
// Explanation: The longest palindrome that can be built is "a", whose length is 1.

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int longestPalindrome(string s) {

    // Har character ki frequency store karne ke liye hashmap
    unordered_map<char, int> f;
    // Characters ki frequency count karo
    for (int i = 0; i < s.size(); i++) {
        f[s[i]]++;
    }
    // Check karega koi odd frequency hai ya nahi
    bool odd = false;
    // Palindrome ki maximum length store karega
    int res = 0;
    // Pehle even frequency characters ko add karo
    for (auto i : f) {
        int val = i.second;
        // Even frequency puri palindrome me use ho sakti hai
        if (val % 2 == 0) {
            res += val;
        }
        else {
            // Odd frequency character mila
            odd = true;
        }
    }

    // Agar koi odd frequency nahi hai
    // To current result hi answer hai
    if (odd == false) {
        return res;
    }

    // Odd frequency characters me se even part add karo
    for (auto i : f) {
        int val = i.second;
        // Odd frequency me se 1 character hata do
        if (val % 2 == 1) {
            res += val - 1;
        }
    }
    // Ek odd character palindrome ke center me use kar sakte hain
    return res + 1;
}

int main() {
    string s;
    // User se string input lena
    cout << "Enter string: ";
    cin >> s;
    // Function call karke answer store karo
    int result = longestPalindrome(s);
    // Final answer print karo
    cout << "Longest Palindrome Length: " << result << endl;
    return 0;
}