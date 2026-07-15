#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// Function jo sorted array se duplicate elements remove karega
// Aur unique elements ki count return karega
int removeDuplicates(vector<int>& nums) {
    // Agar array empty hai to koi unique element nahi hoga
    if (nums.size() == 0)
        return 0;
    // i -> Last unique element ka index
    int i = 0;
    // j -> Array ko traverse karega (current element check karega)
    int j = 1;
    // k -> Total unique elements count
    // Pehla element hamesha unique hota hai
    int k = 1;
    // Jab tak j array ke end tak nahi pahunchta
    while (j < nums.size()) {
        // Agar current element duplicate hai
        if (nums[j] == nums[i]) {
            // Ignore karo aur next element par chale jao
            j++;
        }
        else {
            // Naya unique element mila
            // Use next position par place kar do
            nums[i + 1] = nums[j];
            // Last unique index ko update karo
            i++;
            // Next element check karne ke liye j badhao
            j++;
            // Unique elements ki count badhao
            k++;
        }
    }
    // Total unique elements return karo
    return k;
}

int main() {
    // Sorted array
    vector<int> nums = {1, 1, 2};
    // Function call
    int k = removeDuplicates(nums);
    // Unique elements ki count print karo
    cout << "Number of unique elements: " << k << endl;
    // Sirf first k elements hi valid unique elements hain
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}