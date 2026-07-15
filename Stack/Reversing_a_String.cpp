#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

string reverseString(string str)
{
    stack<char> st;
    // Push all characters into the stack
    for(int i = 0; i < str.length(); i++)
    {
        st.push(str[i]);
    }
    string reversed = "";
    // Pop characters from the stack
    while(!st.empty())
    {
        reversed = reversed + st.top();
        st.pop();
    }
    return reversed;
}

int main()
{
    string str = "Hello";
    cout << "Original String: " << str << endl;
    cout << "Reversed String: " << reverseString(str);
    return 0;
}