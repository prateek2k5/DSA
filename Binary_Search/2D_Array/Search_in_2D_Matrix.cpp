// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// Example 2:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); //total rows
        int m = matrix[0].size(); //total columns
        int low = 0;
        int high = (n * m) - 1;

        while (low <= high) {
            // Mid index nikal rahe hain virtual 1D array ke hisaab se
            int mid = low + (high - low) / 2;
            // 1D index ko 2D row aur column me convert kar rahe hain
            int row = mid / m;
            int col = mid % m;
            if (matrix[row][col] == target) {
                return true;
            }
            // Target bada hai to right half me search karenge
            else if (matrix[row][col] < target) {
                low = mid + 1;
            }
            // Target chhota hai to left half me search karenge
            else {
                high = mid - 1;
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