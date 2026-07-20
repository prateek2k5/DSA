// Example 1:
// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4

// Example 2:
// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        // Jab tak search space valid hai
        while (low <= high) {
            // Middle index nikalo
            int guess = (low + high) / 2;
            // Target mil gaya
            if (nums[guess] == target)
                return guess;
            // Target right side me hai
            if (nums[guess] < target)
                low = guess + 1;
            // Target left side me hai
            else
                high = guess - 1;
        }
        // Target nahi mila
        return -1;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int ans = obj.search(nums, target);
    if (ans != -1)
        cout << "Target found at index: " << ans << endl;
    else
        cout << "Target not found!" << endl;
    return 0;
}
