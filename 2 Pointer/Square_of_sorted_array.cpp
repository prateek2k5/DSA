#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> pos;
    vector<int> neg;

    // Separate positive and negative numbers
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= 0) {
            pos.push_back(nums[i]);
        }
        else {
            neg.push_back(nums[i]);
        }
    }

    // Square positive numbers
    for (int k = 0; k < pos.size(); k++) {
        pos[k] = pos[k] * pos[k];
    }

    // Square negative numbers
    for (int l = 0; l < neg.size(); l++) {
        neg[l] = neg[l] * neg[l];
    }

    // Reverse negative squares
    reverse(neg.begin(), neg.end());

    int a = 0, b = 0, id = 0;
    int n = pos.size();
    int m = neg.size();
    vector<int> res(n + m);

    // Merge two sorted arrays
    while (a < n && b < m) {
        if (pos[a] <= neg[b]) {
            res[id] = pos[a];
            id++;
            a++;
        }
        else {
            res[id] = neg[b];
            id++;
            b++;
        }
    }

    // Remaining positive elements
    while (a < n) {
        res[id] = pos[a];
        id++;
        a++;
    }

    // Remaining negative elements
    while (b < m) {
        res[id] = neg[b];
        id++;
        b++;
    }
    return res;
}

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = sortedSquares(nums);
    cout << "Sorted Squares: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}