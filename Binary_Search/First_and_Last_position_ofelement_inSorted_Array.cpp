// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Example 3:
// Input: nums = [], target = 0
// Output: [-1,-1]
 
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int firstocc = -1;
        int lastocc = -1;

        // First Occurrence find karo
        while (low <= high) {
            // Middle index nikalo
            int guess = (low + high) / 2;
            // Target right side me hai
            if (nums[guess] < target) {
                low = guess + 1;
            }
            // Target left side me hai
            else if (nums[guess] > target) {
                high = guess - 1;
            }
            // Target mila, aur left me first occurrence dhundo
            else {
                firstocc = guess;
                high = guess - 1;
            }
        }

        // Last occurrence ke liye pointers reset karo
        low = 0;
        high = nums.size() - 1;
        // Last Occurrence find karo
        while (low <= high) {
            // Middle index nikalo
            int guess = (low + high) / 2;
            // Target right side me hai
            if (nums[guess] < target) {
                low = guess + 1;
            }
            // Target left side me hai
            else if (nums[guess] > target) {
                high = guess - 1;
            }
            // Target mila, aur right me last occurrence dhundo
            else {
                lastocc = guess;
                low = guess + 1;
            }
        }
        // First aur Last occurrence return karo
        return {firstocc, lastocc};
    }
};

int main() {
    Solution obj;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> ans = obj.searchRange(nums, target);
    cout << "First Occurrence Index: " << ans[0] << endl;
    cout << "Last Occurrence Index : " << ans[1] << endl;
    return 0;
}