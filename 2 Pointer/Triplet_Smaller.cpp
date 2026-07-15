#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        int count = 0;
        int n = arr.size();
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if (sum < target) {
                    count += (right - left);
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return count;
    }
};

int main() {
    vector<int> arr = {-2, 0, 1, 3};
    int target = 2;
    Solution obj;
    cout << obj.countTriplets(arr, target);
    return 0;
}