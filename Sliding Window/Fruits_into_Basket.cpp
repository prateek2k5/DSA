#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> hash;
        int low = 0;
        int res = INT_MIN;
        int n = fruits.size();
        int k = 2;
        for (int high = 0; high < n; high++) {
            hash[fruits[high]]++;
            while (hash.size() > k) {
                hash[fruits[low]]--;
                if (hash[fruits[low]] == 0) {
                    hash.erase(fruits[low]);
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
    int n;
    cout << "Enter number of fruits: ";
    cin >> n;
    vector<int> fruits(n);
    cout << "Enter fruits: ";
    for (int i = 0; i < n; i++) {
        cin >> fruits[i];
    }
    Solution obj;
    cout << "Maximum fruits collected = " << obj.totalFruit(fruits);
    return 0;
}