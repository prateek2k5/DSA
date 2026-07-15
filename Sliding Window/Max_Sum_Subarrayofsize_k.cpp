#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int low = 0;
        int high = k - 1;
        int sum = 0;
        int res = 0;
        int n = arr.size();
        // Sum of first window
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        // Sliding window
        while (high < n) {
            res = max(res, sum);
            low++;
            high++;
            if (high == n) {
                break;
            }
            sum = sum - arr[low - 1];
            sum = sum + arr[high];
        }
        return res;
    }
};

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter window size (k): ";
    cin >> k;
    Solution obj;
    cout << "Maximum Subarray Sum = " << obj.maxSubarraySum(arr, k);
    return 0;
}