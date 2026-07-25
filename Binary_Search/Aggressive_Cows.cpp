// Example-1
// Input: arr[] = [1, 2, 4, 8, 9], k = 3
// Output: 3
// Explanation: The first cow can be placed at arr[0], the second at arr[2], and the third at arr[3].
// The minimum distance between any two cows is 3 (between arr[0] and arr[2]), which is the maximum possible 
// among all valid arrangements.

// Example-2
// Input: arr[] = [10, 1, 2, 7, 5], k = 3
// Output: 4
// Explanation: The first cow can be placed at arr[0], the second at arr[1], and the third at arr[4]. 
// In this arrangement, the minimum distance between any two cows is 4 (between arr[1] and arr[4]), which is 
// the maximum possible among all valid arrangements.


#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Check karo ki given minimum distance par
    // k cows ko place kar sakte hain ya nahi
    bool fun(vector<int> &arr, int n, int k, int guess) {
        int cow = 1;          // Pehli cow pehle stall me rakh do
        int pos = arr[0];     // Last placed cow ki position

        // Baaki stalls check karo
        for (int i = 1; i < n; i++) {
            int dist = arr[i] - pos;
            // Distance kam hai to next stall dekho
            if (dist < guess) {
                continue;
            }
            // Distance sufficient hai,
            // yahan ek aur cow rakh do
            else {
                cow++;
                pos = arr[i];
            }
        }
        // Agar k ya usse zyada cows place ho gayi,
        // to ye distance possible hai
        return (cow >= k);
    }

    int aggressiveCows(vector<int> &arr, int k) {
        int n = arr.size();
        // Stall positions ko sort karo
        sort(arr.begin(), arr.end());
        // Minimum possible distance
        int low = 1;
        // Maximum possible distance
        int high = arr[n - 1] - arr[0];
        int res = -1;
        // Binary Search on Answer
        while (low <= high) {
            // Current minimum distance guess karo
            int guess = (low + high) / 2;
            // Check karo ye distance possible hai ya nahi
            if (fun(arr, n, k, guess)) {

                // Distance valid hai,
                // aur bada distance try karo
                res = guess;
                low = guess + 1;
            }
            else {

                // Distance zyada hai,
                // ise kam karo
                high = guess - 1;
            }
        }
        // Maximum minimum distance return karo
        return res;
    }
};

int main() {

    Solution obj;
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;
    cout << "Maximum Minimum Distance: "
         << obj.aggressiveCows(stalls, k) << endl;
    return 0;
}