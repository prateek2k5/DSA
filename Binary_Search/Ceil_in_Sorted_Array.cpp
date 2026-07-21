// Input: arr[] = [1, 2, 8, 10, 11, 12, 19], x = 5
// Output: 2
// Explanation: Smallest number greater than 5 is 8, whose index is 2.

// Input: arr[] = [1, 2, 8, 10, 11, 12, 19], x = 20
// Output: -1
// Explanation: No element greater than 20 is found. So output is -1.

// Input: arr[] = [1, 1, 2, 8, 10, 11, 12, 19], x = 0
// Output: 0
// Explanation: Smallest number greater than 0 is 1, whose indices are 0 and 1. The index of the first occurrence is 0.

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findCeil(vector<int>& arr, int x) {
        int low = 0;
        int high = arr.size() - 1;
        int res = -1; // Ceil ka index store karega

        // Binary Search
        while (low <= high) {
            // Middle index nikalo
            int guess = (low + high) / 2;
            // Agar middle value chhoti hai to right side jao
            if (arr[guess] < x) {
                low = guess + 1;
            }
            // Possible ceil mila, aur left me better answer dhundo
            else {
                res = guess;
                high = guess - 1;
            }
        }
        // Ceil ka index return karo
        return res;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 2, 4, 6, 8, 10};
    int x = 5;
    int index = obj.findCeil(arr, x);
    if (index != -1)
        cout << "Ceil of " << x << " is " << arr[index]
             << " at index " << index << endl;
    else
        cout << "Ceil does not exist." << endl;
    return 0;
}