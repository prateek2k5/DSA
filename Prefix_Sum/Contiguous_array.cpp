// Example 1:
// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

// Example 2:
// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

// Example 3:
// Input: nums = [0,1,1,1,1,1,0,0,0]
// Output: 6
// Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int zero = 0, one = 0;
        unordered_map<int, int> f;   // Stores first occurrence of (zero - one)
        int res = 0;
        for (int i = 0; i < n; i++) {
            // Count 0s and 1s
            if (nums[i] == 0)
                zero++;
            else
                one++;
            // Difference between number of 0s and 1s
            int diff = zero - one;
            // If diff is 0, subarray from 0 to i is valid
            if (diff == 0)
                res = max(res, i + 1);
            // Store first occurrence of diff
            if (f.find(diff) == f.end()) {
                f[diff] = i;
            }
            else {
                // Same diff found again
                int len = i - f[diff];
                res = max(res, len);
            }
        }
        return res;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter binary array (0 or 1): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution obj;
    int ans = obj.findMaxLength(nums);
    cout << "Maximum Length = " << ans << endl;
    return 0;
}