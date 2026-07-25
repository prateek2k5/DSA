// Example 1:
// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.

// Example 2:
// Input: nums = [1,2,1,3,5,6,4]
// Output: 5
// Explanation: Your function can return either index number 1 where the peak element is 2,
// or index number 5 where the peak element is 6.

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 2;      // mid+1 use karna hai, isliye last-1 tak
        int res = n - 1;       // Agar kahin na mila to last element peak hoga
        // Binary Search
        while (low <= high) {
            // Middle index nikalo
            int guess = (low + high) / 2;
            /*
                Agar right wala element bada hai,
                matlab abhi chadhai (ascending) chal rahi hai.
                Peak right side me hogi.
            */
            if (nums[guess] < nums[guess + 1]) {
                low = guess + 1;
            }
            /*
                Warna hum peak ya descending part me hain.
                Current index possible peak hai,
                aur left me pehla peak dhundte hain.
            */
            else {
                res = guess;
                high = guess - 1;
            }
        }
        // Peak ka index return karo
        return res;
    }
};

int main() {

    Solution obj;
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    int ans = obj.findPeakElement(nums);
    cout << "Peak Index : " << ans << endl;
    cout << "Peak Value : " << nums[ans] << endl;
    return 0;
}