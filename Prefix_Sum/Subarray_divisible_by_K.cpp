#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        // Empty prefix sum has remainder 0
        mp[0] = 1;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            // Handle negative remainders
            int rem = sum % k;
            if (rem < 0) {
                rem += k;
            }
            ans += mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int k;
    cout << "Enter value of k: ";
    cin >> k;
    Solution obj;
    int result = obj.subarraysDivByK(nums, k);
    cout << "Number of subarrays divisible by " << k << " = " << result << endl;
    return 0;
}