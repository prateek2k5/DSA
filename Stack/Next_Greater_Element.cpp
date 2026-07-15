// Example 1:
// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.

// Example 2:
// Input: nums = [1,2,3,4,3]
// Output: [2,3,4,-1,4]

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to find Next Greater Element in a Circular Array
vector<int> nextGreaterElements(vector<int>& nums)
{
    int n = nums.size();
    // Result vector ko -1 se initialize kar diya
    // Agar kisi element ka next greater nahi milega to -1 hi rahega
    vector<int> res(n, -1);
    // Monotonic Decreasing Stack
    // Isme hum elements store karenge
    stack<int> st;
    // Circular array ko simulate karne ke liye
    // Array ko 2 baar traverse karenge (2*n elements)
    for(int i = 2 * n - 1; i >= 0; i--)
    {
        /*
            % n ka use kyu kiya?

            Original array ke index sirf 0 se n-1 tak hote hain.
            Agar n = 3 hai, to i ki values hongi:
            i = 5 -> 5 % 3 = 2
            i = 4 -> 4 % 3 = 1
            i = 3 -> 3 % 3 = 0
            i = 2 -> 2 % 3 = 2
            i = 1 -> 1 % 3 = 1
            i = 0 -> 0 % 3 = 0

            Isliye traversal ban jata hai:

            2 -> 1 -> 0 -> 2 -> 1 -> 0

            Matlab bina naya array banaye
            hum circular array ko traverse kar pa rahe hain.
        */
        int curr = nums[i % n];
        // Jab tak stack ka top current element se
        // chota ya equal hai usse hata do
        // Kyunki wo kabhi next greater nahi ban sakta
        while(!st.empty() && st.top() <= curr)
        {
            st.pop();
        }
        /*
            Pehli traversal (i >= n)
            Sirf stack prepare karne ke liye hoti hai.

            Jab i < n hoga tabhi answer fill karenge.
        */
        if(i < n)
        {
            if(st.empty())
            {
                // Koi greater element nahi mila
                res[i] = -1;
            }
            else
            {
                // Stack ka top hi next greater element hai
                res[i] = st.top();
            }
        }
        // Current element ko stack me push kar do
        // Taaki ye left side ke elements ke liye
        // next greater ban sake
        st.push(curr);
    }
    return res;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> ans = nextGreaterElements(nums);
    cout << "\nNext Greater Elements: ";
    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}