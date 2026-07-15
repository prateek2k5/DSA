// Input: arr = [1,-2,0,3]
// Output: 4
// Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        // Maximum subarray sum ending at current index
        // WITHOUT deleting any element.
        int no_delete = arr[0];
        // Maximum subarray sum ending at current index
        // AFTER deleting exactly one element.
        // Initially impossible, so initialize with INT_MIN.
        int one_delete = INT_MIN;
        // Stores the overall maximum answer.
        int res = arr[0];
        int n = arr.size();
        // Traverse the array from the second element.
        for (int i = 1; i < n; i++) {
            // Store previous values because they are needed
            // before updating no_delete and one_delete.
            int prev_no_delete = no_delete;
            int prev_one_delete = one_delete;
            // -------------------------
            // Case 1: No deletion used
            // -------------------------
            // Either:
            // 1. Extend the previous subarray.
            // 2. Start a new subarray from the current element.
            no_delete = max(prev_no_delete + arr[i], arr[i]);
            // -------------------------
            // Case 2: One deletion used
            // -------------------------
            int v2;
            // If deletion has never been used before,
            // simply start a new subarray from arr[i].
            if (prev_one_delete == INT_MIN)
                v2 = arr[i];
            else
                // Extend the previous subarray
                // where one deletion has already been used.
                v2 = prev_one_delete + arr[i];
            // Two possibilities:
            //
            // 1. Continue a subarray where one deletion
            //    has already happened (v2).
            //
            // 2. Delete the CURRENT element.
            //    In that case, the answer becomes the
            //    previous no_delete value.
            one_delete = max(v2, prev_no_delete);
            // Update the overall maximum answer.
            res = max(res, max(no_delete, one_delete));
        }
        return res;
    }
};

int main() {

    vector<int> arr = {1, -2, 0, 3};

    Solution obj;

    cout << "Maximum Sum with One Deletion = "
         << obj.maximumSum(arr) << endl;

    return 0;
}