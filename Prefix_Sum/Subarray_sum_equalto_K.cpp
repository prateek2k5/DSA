#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int res = 0;
        unordered_map<int, int> f;
        // Empty prefix sum
        f[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            // Update prefix sum
            sum += nums[i];
            // Required prefix sum
            int ques = sum - k;
            // Frequency of required prefix
            int freq = f[ques];
            // Add all valid subarrays
            res += freq;
            // Store current prefix sum
            f[sum]++;
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;
    Solution obj;
    cout << "Number of Subarrays = "
         << obj.subarraySum(nums, k) << endl;
    return 0;
}