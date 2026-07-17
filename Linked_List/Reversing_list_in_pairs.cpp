// Example 1:
// Input: head = [1,2,3,4]
// Output: [2,1,4,3]

// Example 2:
// Input: head = []
// Output: []

// Example 3:
// Input: head = [1]
// Output: [1]

// Example 4:
// Input: head = [1,2,3]
// Output: [2,1,3]

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// -------------------- Definition of Linked List Node --------------------
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:

    // ------------------------------------------------------------------
    // Function: reverse()
    // Kaam:
    // Linked List ke starting ke 'times' nodes ko reverse karta hai.
    // Yeh function sirf links reverse karta hai, koi value return nahi karta.
    // ------------------------------------------------------------------
    void reverse(ListNode* head, int times) {
        ListNode* curr = head;   // Current node jisko process karna hai
        ListNode* prev = NULL;   // Previous node initially NULL
        while (times--) {
            // Next node ko save kar lo taki link na toot jaye
            ListNode* next = curr->next;
            // Current node ka pointer reverse direction me kar do
            curr->next = prev;
            // Prev aur Curr ko ek step aage badhao
            prev = curr;
            curr = next;
        }
    }

    ListNode* swapPairs(ListNode* head) {
        // Agar list empty hai to wahi return kar do
        if (head == NULL) {
            return head;
        }
        // Left = Current pair ka first node
        ListNode* left = head;
        // Right = Current pair ka second node
        ListNode* right;
        // Final answer ka head
        ListNode* res = NULL;
        // Previous reversed pair ka last node
        ListNode* prevleft = NULL;
        while (true) {
            // Right ko left se initialize karo
            right = left;
            int size = 2;
            // Right ko pair ke last node tak le jao
            for (int i = 0; i < size - 1; i++) {
                // Agar node nahi mili to pair complete nahi hai
                if (right == NULL) {
                    break;
                }
                right = right->next;
            }
            // ----------------------------------------------------------
            // Agar complete pair mil gaya
            // ----------------------------------------------------------
            if (right) {
                // Agle pair ka starting node save kar lo
                ListNode* nextleft = right->next;
                // Current pair reverse karo
                reverse(left, size);
                // Agar pehle bhi koi pair reverse hua tha
                // uske last node ko current reversed pair se connect karo
                if (prevleft) {
                    prevleft->next = right;
                }
                // Reverse ke baad left pair ka last node ban jata hai
                prevleft = left;
                // Next iteration ke liye left update karo
                left = nextleft;
                // Pehli baar answer ka head set karo
                if (res == NULL) {
                    res = right;
                }
            }
            // ----------------------------------------------------------
            // Agar pair complete nahi hai
            // Matlab last me sirf ek node bachi hai
            // ----------------------------------------------------------
            else {
                // Last single node ko previous pair se connect karo
                if (prevleft) {
                    prevleft->next = left;
                }
                // Agar list me sirf ek hi node thi
                if (res == NULL) {
                    res = left;
                }
                break;
            }
        }
        return res;
    }
};

// -------------------- Helper Function --------------------
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// -------------------- Main Function --------------------
int main() {
    // Linked List:
    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout << "Original List : ";
    printList(head);
    Solution obj;
    head = obj.swapPairs(head);
    cout << "After Swapping Pairs : ";
    printList(head);
    return 0;
}