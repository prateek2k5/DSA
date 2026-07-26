// Given an array arr[] of integers, where each element arr[i] represents the number of pages 
// in the i-th book. You also have an integer k representing the number of students. 
// The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// All books must be allocated.

// The objective is to minimize the maximum number of pages assigned to any student. 
// In other words, out of all possible allocations, find the arrangement where the student 
// who receives the most pages still has the smallest possible maximum. 
// If it is not possible to allocate books to all students, return -1;

// Example-1
// Input: arr[] = [12, 34, 67, 90], k = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// => [12] and [34, 67, 90] Maximum Pages = 191
// => [12, 34] and [67, 90] Maximum Pages = 157
// => [12, 34, 67] and [90] Maximum Pages = 113.
// The third combination has the minimum pages assigned to a student which is 113.

// Example-2
// Input: arr[] = [15, 17, 20], k = 5
// Output: -1
// Explanation: Since there are more students than total books, it's impossible to allocate a
//  book to each student.

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Check karo ki given maximum pages per student
    // par books allocate ho sakti hain ya nahi
    bool fun(vector<int> &arr, int n, long long guess, int k) {
        int stud = 1;      // Pehla student
        int pages = 0;     // Current student ke pages
        for (int i = 0; i < n; i++) {
            // Agar current student ko ye book de sakte hain
            if (pages + arr[i] <= guess) {
                pages += arr[i];
            }
            // Nahi to naya student allocate karo
            else {
                stud++;
                pages = arr[i];
                // Students limit cross ho gayi
                if (stud > k) {
                    return false;
                }
            }
        }
        // Allocation possible hai
        return true;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        // Students books se zyada hain
        if (n < k) {
            return -1;
        }
        // Minimum possible answer
        int low = 0;
        // Maximum possible answer (sum of all pages)
        long long high = 0;
        long long res = -1;
        // Search space find karo
        for (int i = 0; i < n; i++) {
            low = max(low, arr[i]);
            high += arr[i];
        }

        // Binary Search on Answer
        while (low <= high) {
            // Current maximum pages guess karo
            long long guess = low + (high - low) / 2;
            // Agar allocation possible hai
            if (fun(arr, n, guess, k)) {
                // Answer save karo
                res = guess;
                // Aur chhota answer dhundo
                high = guess - 1;
            }
            // Allocation possible nahi hai
            else {
                // Pages limit badhao
                low = guess + 1;
            }
        }
        return (int)res;
    }
};

int main() {

    Solution obj;
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    cout << "Minimum Pages = "
         << obj.findPages(arr, k);
    return 0;
}