// Example 1:
// Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
// Output: 13
// Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

// Example 2:
// Input: matrix = [[-5]], k = 1
// Output: -5

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Guess se chhote ya equal elements count karne ka function
    int fun(vector<vector<int>> &matrix, int n, int m, int guess) {
        int row = n - 1;
        int col = 0;
        int count = 0;
        while (row >= 0 && col < m) {
            // Agar current element <= guess hai to is column ke upar ke
            // saare elements bhi <= guess honge
            if (matrix[row][col] <= guess) {
                count += row + 1;
                col++;
            }
            // Current element bada hai to upar move karo
            else {
                row--;
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();
        int m = matrix[0].size();
        // Answer value range me lie karega
        int low = matrix[0][0];
        int high = matrix[n - 1][m - 1];
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int ans = fun(matrix, n, m, mid);
            // Agar count kam hai to answer right side me hoga
            if (ans < k) {
                low = mid + 1;
            }
            // Warna ye possible answer hai, aur chhota answer dhundte hain
            else {
                res = mid;
                high = mid - 1;
            }
        }
        return res;
    }
};

int main() {

    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int k;
    cout << "Enter k: ";
    cin >> k;
    Solution obj;
    cout << "Kth Smallest Element = " << obj.kthSmallest(matrix, k);
    return 0;
}