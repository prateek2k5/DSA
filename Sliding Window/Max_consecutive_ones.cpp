#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0;
        int zeroCount = 0;
        int res = 0;
        for (int high = 0; high < nums.size(); high++) {
            if (nums[high] == 0) {
                zeroCount++;
            }
            while (zeroCount > k) {
                if (nums[low] == 0) {
                    zeroCount--;
                }
                low++;
            }
            int len = high - low + 1;
            res = max(res, len);
        }
        return res;
    }
};

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter array elements (0 or 1): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter k: ";
    cin >> k;
    Solution obj;
    cout << "Maximum consecutive ones = "
         << obj.longestOnes(nums, k);

    return 0;
}