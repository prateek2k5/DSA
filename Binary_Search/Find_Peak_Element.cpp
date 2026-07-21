// Example 1:
// Input: arr = [0,1,0]
// Output: 1

// Example 2:
// Input: arr = [0,2,1,0]
// Output: 1

// Example 3:
// Input: arr = [0,10,5,2]
// Output: 1
 
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        int res = -1; // Peak ka index store karega
        // Binary Search
        while (low <= high) {
            // Middle index nikalo
            int guess = (low + high) / 2;
            /*
                Pahad ka example:

                        Peak
                         /\
                        /  \
                       /    \
                ------/      \------

                Hum hamesha mid par khade hote hain aur
                sirf apne RIGHT wale insaan ko dekhte hain.
            */

            // Agar right wala element bada hai,
            // matlab abhi pahad ki chadhai (ascending) chal rahi hai.
            // Peak abhi aage hai, isliye right move karo.
            if (arr[guess] < arr[guess + 1]) {
                low = guess + 1;
            }
            // Agar right wala element chhota ya equal hai,
            // matlab ya to peak par khade hain ya peak cross kar chuke hain.
            // Current index ko possible answer maan lo
            // aur dekho kya left side me aur pehle peak mil sakti hai.
            else {
                res = guess;
                high = guess - 1;
            }
        }
        // Peak ka index return karo
        return res;
    }
};

int main() {
    Solution obj;
    // Mountain Array
    vector<int> arr = {1, 3, 6, 9, 7, 4, 2};
    int peak = obj.peakIndexInMountainArray(arr);
    cout << "Peak Index : " << peak << endl;
    cout << "Peak Element : " << arr[peak] << endl;
    return 0;
}

