// Input: start[] = [1, 10, 7], end[] = [4, 15, 10]
// Output: 1
// Explanation: Since all the meetings are held at different times, it is possible to attend all the meetings in a single room.

// Input: start[] = [2, 9, 6], end[] = [4, 12, 10]
// Output: 2
// Explanation: 1st and 2nd meetings at one room but for 3rd meeting one another room required.

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int n = start.size();
        // Start aur end time ko alag-alag sort karo
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int rooms = 0;   // Current occupied rooms
        int res = 0;     // Maximum rooms required
        int i = 0, j = 0;
        // Dono arrays ko ek sath traverse karo
        while (i < n && j < n) {
            // Nayi meeting start ho rahi hai
            if (start[i] < end[j]) {
                rooms++;
                res = max(res, rooms);
                i++;
            }
            else {
                // Ek meeting khatam ho gayi
                rooms--;
                j++;
            }
        }
        return res;
    }
};

int main() {
    int n;
    cout << "Enter number of meetings: ";
    cin >> n;
    vector<int> start(n), end(n);
    cout << "Enter start times:\n";
    for (int i = 0; i < n; i++) {
        cin >> start[i];
    }
    cout << "Enter end times:\n";
    for (int i = 0; i < n; i++) {
        cin >> end[i];
    }
    Solution obj;
    int ans = obj.minMeetingRooms(start, end);
    cout << "\nMinimum Meeting Rooms Required = " << ans << endl;
    return 0;
}