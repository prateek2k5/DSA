// Input: nums = [1,-3,2,3,-4]
// Output: 5
// Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // Max and min subarray ending at current index
        int max_end = nums[0];
        int min_end = nums[0];
        // Overall max and min subarray sums
        int max_sum = nums[0];
        int min_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            // Kadane for maximum sum
            max_end = max(nums[i], max_end + nums[i]);
            max_sum = max(max_sum, max_end);
            // Kadane for minimum sum
            min_end = min(nums[i], min_end + nums[i]);
            min_sum = min(min_sum, min_end);
        }
        // Maximum absolute sum
        return max(abs(max_sum), abs(min_sum));
    }
};

int main() {
    vector<int> nums = {1, -3, 2, 3, -4};
    Solution obj;
    cout << "Maximum Absolute Sum = "
         << obj.maxAbsoluteSum(nums) << endl;
    return 0;
}