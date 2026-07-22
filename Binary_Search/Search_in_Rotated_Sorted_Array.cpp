// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// Example 3:
// Input: nums = [1], target = 0
// Output: -1

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        int low = 0;
        int high = n;
        // Binary Search
        while (low <= high) {
            // Middle index nikalo
            int guess = (low + high) / 2;
            // Target mil gaya
            if (nums[guess] == target) {
                return guess;
            }
            // Agar mid last element se bada hai,
            // matlab hum left sorted part me hain.
            if (nums[guess] > nums[n]) {
                // Agar target mid se bada hai,
                // to right side search karo.
                if (nums[guess] < target) {
                    low = guess + 1;
                }
                else {
                    // Agar target first element se chhota hai,
                    // to target right rotated part me hoga.
                    if (nums[0] > target) {
                        low = guess + 1;
                    }
                    // Warna target left sorted part me hi hoga.
                    else {
                        high = guess - 1;
                    }
                }
            }

            // Mid right sorted part me hai.
            else {
                // Agar target mid se chhota hai,
                // to left side search karo.
                if (nums[guess] > target) {
                    high = guess - 1;
                }
                else {
                    // Agar target last element se bada hai,
                    // to target left sorted part me hoga.
                    if (nums[n] < target) {
                        high = guess - 1;
                    }

                    // Warna target right sorted part me hoga.
                    else {
                        low = guess + 1;
                    }
                }
            }
        }
        // Target nahi mila
        return -1;
    }
};

int main() {

    Solution obj;
    // Rotated Sorted Array
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int ans = obj.search(nums, target);
    if (ans != -1)
        cout << "Target found at index: " << ans << endl;
    else
        cout << "Target not found!" << endl;
    return 0;
}