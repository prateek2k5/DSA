// Example 1:
// Input: ransomNote = "a", magazine = "b"
// Output: false

// Example 2:
// Input: ransomNote = "aa", magazine = "ab"
// Output: false

// Example 3:
// Input: ransomNote = "aa", magazine = "aab"
// Output: true
 

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Check karega ki magazine me required characters enough hain ya nahi
bool fun(unordered_map<char, int> have,
         unordered_map<char, int> need) {
    // Need hashmap ko traverse karenge
    for (auto i : need) {
        char c = i.first;       // Current character
        int f_need = i.second;  // Required frequency
        int f_have = have[c];   // Available frequency
        // Agar required characters enough nahi hain
        if (f_have < f_need) {
            return false;
        }
    }
    return true;
}

bool canConstruct(string ransomNote, string magazine) {
    // Magazine ke characters ki frequency
    unordered_map<char, int> have;
    // RansomNote ke required characters ki frequency
    unordered_map<char, int> need;
    // RansomNote ki frequency count karo
    for (int i = 0; i < ransomNote.size(); i++) {
        need[ransomNote[i]]++;
    }
    // Magazine ki frequency count karo
    for (int i = 0; i < magazine.size(); i++) {
        have[magazine[i]]++;
    }
    // Check karo ransomNote bana sakte hain ya nahi
    return fun(have, need);
}

int main() {
    string ransomNote, magazine;
    // User se input lena
    cout << "Enter Ransom Note: ";
    cin >> ransomNote;
    cout << "Enter Magazine: ";
    cin >> magazine;
    // Function call karke result check karo
    if (canConstruct(ransomNote, magazine)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    return 0;
}