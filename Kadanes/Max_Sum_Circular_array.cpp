#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = nums[0];
        // Max and min subarray ending at current index
        int max_end = nums[0];
        int min_end = nums[0];
        // Overall max and min subarray sums
        int max_sum = nums[0];
        int min_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            total_sum += nums[i];
            // Kadane for maximum sum
            max_end = max(nums[i], max_end + nums[i]);
            max_sum = max(max_sum, max_end);
            // Kadane for minimum sum
            min_end = min(nums[i], min_end + nums[i]);
            min_sum = min(min_sum, min_end);
        }
        // All elements are negative
        if (max_sum < 0)
            return max_sum;
        // Maximum of normal and circular subarray
        return max(max_sum, total_sum - min_sum);
    }
};

int main() {
    vector<int> nums = {5, -3, 5};
    Solution obj;
    cout << "Maximum Circular Subarray Sum = "
         << obj.maxSubarraySumCircular(nums) << endl;
    return 0;
}