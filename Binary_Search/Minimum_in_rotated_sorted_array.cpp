// Example 1:
// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.

// Example 2:
// Input: nums = [4,5,6,7,0,1,2]
// Output: 0
// Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

// Example 3:
// Input: nums = [11,13,15,17]
// Output: 11
// Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() - 1;
        int low = 0, high = n;
        int res = -1; // Minimum element ka index
        while (low <= high) {
            // Middle index nikalo
            int guess = (low + high) / 2;

            /*
                Rotated Array:
                4 5 6 7 0 1 2
                        ↑
                    Last = 2

                Mid ko last element se compare karo.
            */

            // Mid left sorted part me hai,
            // minimum right side me hoga.
            if (nums[guess] > nums[n]) {
                low = guess + 1;
            }
            // Mid minimum wale part me hai.
            // Answer save karo aur left me aur pehla minimum dhundo.
            else {
                res = guess;
                high = guess - 1;
            }
        }
        return nums[res];
    }
};

int main() {

    Solution obj;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "Minimum Element: " << obj.findMin(nums);
    return 0;
}