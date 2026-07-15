// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "()[]{}"
// Output: true

// Example 3:
// Input: s = "(]"
// Output: false

// Example 4:
// Input: s = "([])"
// Output: true

// Example 5:
// Input: s = "([)]"
// Output: false

#include<bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check whether the parentheses are valid
bool isValid(string s)
{
    stack<char> st;
    // Traverse the string using a normal for loop
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        // If it is an opening bracket, push it into the stack
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            // If stack is empty, no matching opening bracket exists
            if (st.empty())
            {
                return false;
            }
            // Check if the top of the stack matches the current closing bracket
            if ((ch == ')' && st.top() == '(') ||
                (ch == '}' && st.top() == '{') ||
                (ch == ']' && st.top() == '['))
            {
                // Matching pair found, remove the opening bracket
                st.pop();
            }
            else
            {
                // Brackets do not match
                return false;
            }
        }
    }
    // If stack is empty, all brackets are matched
    return st.empty();
}

int main()
{
    string s;
    cout << "Enter the parentheses string: ";
    cin >> s;
    if (isValid(s))
    {
        cout << "Valid Parentheses" << endl;
    }
    else
    {
        cout << "Invalid Parentheses" << endl;
    }
    return 0;
}