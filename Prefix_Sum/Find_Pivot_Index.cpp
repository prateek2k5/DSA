#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int sum = 0;
        // Calculate total sum of the array
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        // Check if index 0 is the pivot
        if (sum - nums[0] == 0) {
            return 0;
        }
        // Check remaining indices
        for (int j = 1; j < nums.size(); j++) {
            // Add previous element to left sum
            left += nums[j - 1];
            // Calculate right sum
            int right = sum - nums[j] - left;
            // If left and right sums are equal, return pivot index
            if (left == right) {
                return j;
            }
        }
        return -1;
    }
};

int main() {
    // Example 1
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    Solution obj;
    int ans = obj.pivotIndex(nums);
    if (ans != -1)
        cout << "Pivot Index = " << ans << endl;
    else
        cout << "No Pivot Index Found" << endl;
    return 0;
}