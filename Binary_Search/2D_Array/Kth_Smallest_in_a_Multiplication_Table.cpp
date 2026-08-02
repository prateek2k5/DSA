// Example 1:
// Input: m = 3, n = 3, k = 5
// Output: 3
// Explanation: The 5th smallest number is 3.

// Example 2:
// Input: m = 2, n = 3, k = 6
// Output: 6
// Explanation: The 6th smallest number is 6.

#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Guess se chhote ya equal kitne numbers hain multiplication table me
    int fun(int n, int m, int guess) {
        int count = 0;
        for (int i = 1; i <= m; i++) {
            // Har row me maximum n elements hi ho sakte hain
            count += min(guess / i, n);
        }
        return count;
    }

    int findKthNumber(int n, int m, int k) {
        // Answer 1 se n*m ke range me hoga
        int low = 1;
        int high = n * m;
        int res = -1;

        while (low <= high) {
            int guess = low + (high - low) / 2;
            int ans = fun(n, m, guess);
            // Count kam hai to answer right side me hoga
            if (ans < k) {
                low = guess + 1;
            }
            // Warna ye possible answer hai, aur chhota answer dhundte hain
            else {
                res = guess;
                high = guess - 1;
            }
        }
        return res;
    }
};

int main() {
    int n, m, k;
    cout << "Enter rows, columns and k: ";
    cin >> n >> m >> k;
    Solution obj;
    cout << "Kth Smallest Number = " << obj.findKthNumber(n, m, k);
    return 0;
}