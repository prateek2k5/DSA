#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min_end = nums[0];
        int max_end = nums[0];
        int res = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int v1 = nums[i];
            int v2 = min_end * nums[i];
            int v3 = max_end * nums[i];
            min_end = min(v1, min(v2, v3));
            max_end = max(v1, max(v2, v3));
            res = max(res, max_end);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {2, 3, -2, 4};
    Solution obj;
    cout << "Maximum Product Subarray = " << obj.maxProduct(nums) << endl;
    return 0;
}