// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
// The guards have gone and will come back in h hours.
// Koko can decide her bananas-per-hour eating speed of k. 
// Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
// If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
// Return the minimum integer k such that she can eat all the bananas within h hours.

// Example 1:
// Input: piles = [3,6,7,11], h = 8
// Output: 4

// Example 2:
// Input: piles = [30,11,23,4,20], h = 5
// Output: 30

// Example 3:
// Input: piles = [30,11,23,4,20], h = 6
// Output: 23

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // Di hui speed par Koko ko total kitne hours lagenge
    long long fun(vector<int>& piles, int n, int speed) {
        // long long use kiya hai kyunki total hours ka sum
        // int ki limit (2,147,483,647) se bada ho sakta hai.
        // Isse integer overflow nahi hoga.
        long long h = 0;

        // Har pile ke liye hours calculate karo
        for (int i = 0; i < n; i++) {
            // Complete division ka result add karo
            h += piles[i] / speed;
            // Agar remainder bacha hai,
            // to 1 extra hour lagega
            if (piles[i] % speed != 0) {
                h++;
            }
        }
        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();

        // Minimum possible speed
        int low = 1;

        // Maximum pile hi maximum possible speed hogi
        int idx = max_element(piles.begin(), piles.end()) - piles.begin();
        int high = piles[idx];

        int res = -1; // Minimum valid speed store karega

        // Binary Search on Answer
        while (low <= high) {
            // Current speed guess karo
            int guess = (low + high) / 2;
            // Is speed par total kitne hours lagenge
            long long hours = fun(piles, n, guess);
            // Agar required hours se zyada lag rahe hain,
            // to speed badhani padegi
            if (hours > h) {
                low = guess + 1;
            }
            // Agar h hours ya usse kam me kaam ho gaya,
            // to ye valid speed hai.
            // Aur chhoti valid speed dhundte hain.
            else {
                res = guess;
                high = guess - 1;
            }
        }
        // Minimum valid speed return karo
        return res;
    }
};

int main() {
    Solution obj;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << "Minimum Eating Speed: "
         << obj.minEatingSpeed(piles, h) << endl;

    return 0;
}