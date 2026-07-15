#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0;
    int j = numbers.size() - 1;

    while (i < j) {
        int sum = numbers[i] + numbers[j];

        if (sum == target) {
            return {i + 1, j + 1};  // 1-indexed
        }
        else if (sum < target) {
            i++;
        }
        else {
            j--;
        }
    }

    return {};
}

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(numbers, target);

    cout << "Indices: ";
    for (int index : result) {
        cout << index << " ";
    }

    return 0;
}