// Example 1:
// Input: text = "nlaebolko"
// Output: 1

// Example 2:
// Input: text = "loonbalxballpoon"
// Output: 2

// Example 3:
// Input: text = "leetcode"
// Output: 0
 
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int maxNumberOfBalloons(string text) {

    // Text ke har character ki frequency store karo
    unordered_map<char, int> have;
    for (int i = 0; i < text.size(); i++) {
        have[text[i]]++;
    }

    // "balloon" banane ke liye required frequency
    unordered_map<char, int> need;
    need['b'] = 1;
    need['a'] = 1;
    need['l'] = 2;
    need['o'] = 2;
    need['n'] = 1;
    // Minimum possible count find karne ke liye
    int res = INT_MAX;

    // Required characters ko traverse karo
    for (auto i : need) {
        char c = i.first;       // Current character
        int fneed = i.second;   // Required frequency
        int fhave = have[c];    // Available frequency
        // Current character se balloon kitni baar ban sakta hai
        int times = fhave / fneed;
        // Minimum times hi final answer hoga
        res = min(res, times);
    }
    return res;
}

int main() {
    string text;
    // User se input lena
    cout << "Enter text: ";
    cin >> text;
    // Function call karke result store karo
    int result = maxNumberOfBalloons(text);
    // Final answer print karo
    cout << "Maximum Number of Balloons: " << result << endl;
    return 0;
}