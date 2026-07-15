// Example 1:
// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

// Example 2:
// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]

// Example 3:
// Input: temperatures = [30,60,90]
// Output: [1,1,0]

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures)
{
    int n = temperatures.size();
    // Result vector
    // Default value 0 hai kyunki agar warmer day nahi mila
    // to answer 0 hi rahega
    vector<int> res(n, 0);
    // Stack me indices store karenge
    stack<int> st;
    // Last element ke baad koi day nahi hota
    // Isliye uska answer 0 hi rahega
    st.push(n - 1);
    // Right se left traverse karenge
    for(int i = n - 2; i >= 0; i--)
    {
        // Jab tak stack ka top current temperature se
        // chota ya equal hai usse hata do
        // Kyunki wo next warmer day nahi ban sakta
        while(!st.empty() && temperatures[st.top()] <= temperatures[i])
        {
            st.pop();
        }
        // Agar stack empty ho gaya
        // to future me koi warmer day nahi hai
        if(st.empty())
        {
            res[i] = 0;
        }
        else
        {
            // Stack ke top ka index - current index
            // = kitne din baad warmer temperature milega
            res[i] = st.top() - i;
        }
        // Current day ka index stack me push kar do
        st.push(i);
    }
    return res;
}

int main()
{
    int n;
    cout << "Enter number of days: ";
    cin >> n;
    vector<int> temperatures(n);
    cout << "Enter temperatures: ";
    for(int i = 0; i < n; i++)
    {
        cin >> temperatures[i];
    }
    vector<int> ans = dailyTemperatures(temperatures);
    cout << "\nDays to wait for a warmer temperature:\n";
    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}