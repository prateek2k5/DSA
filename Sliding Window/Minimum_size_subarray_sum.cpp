#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int high = 0;
        int sum = 0;
        int res = INT_MAX;
        int n = nums.size();
        while (high < n) {
            sum = sum + nums[high];
            while (sum >= target) {
                int len = high - low + 1;
                res = min(res, len);
                sum = sum - nums[low];
                low++;
            }
            high++;
        }
        if (res == INT_MAX) //if not found any solv
            return 0;
        return res;
    }
};

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter target: ";
    cin >> target;
    Solution obj;
    int ans = obj.minSubArrayLen(target, nums);
    cout << "Minimum Subarray Length = " << ans << endl;
    return 0;
}