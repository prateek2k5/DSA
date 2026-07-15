#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    // Function to calculate the sum of squares of digits
    int fun(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        while (fast != 1) {
            slow = fun(slow);
            fast = fun(fun(fast));
            if (slow == fast) {
                if (slow == 1)
                    return true;
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (obj.isHappy(n))
        cout << n << " is a Happy Number." << endl;
    else
        cout << n << " is NOT a Happy Number." << endl;
    return 0;
}