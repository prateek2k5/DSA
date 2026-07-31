// Example 1:
// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// Output: true

// Example 2:
// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
// Output: false

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Bottom-left se search start kar rahe hain
        int row = n - 1;
        int col = 0;

        while (row >= 0 && col < m) {

            if (matrix[row][col] == target) {
                return true;
            }
            // Current value badi hai to upar move karenge
            else if (matrix[row][col] > target) {
                row--;
            }
            // Current value chhoti hai to right move karenge
            else {
                col++;
            }
        }
        return false;
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
    int target;
    cout << "Enter target: ";
    cin >> target;
    Solution obj;
    if (obj.searchMatrix(matrix, target))
        cout << "Target Found\n";
    else
        cout << "Target Not Found\n";
    return 0;
}
