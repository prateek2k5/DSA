#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best_end = nums[0];
        int res = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int v1 = nums[i];
            int v2 = best_end + nums[i];
            best_end = min(v1, v2);
            res = min(res, best_end);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution obj;
    cout << "Maximum Subarray Sum = " << obj.maxSubArray(nums) << endl;
    return 0;
}