// Example 1:
// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// Example 2:
// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// -------------------- Linked List Node --------------------
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

    // Starting ke 'times' nodes ko reverse karta hai
    void reverse(ListNode* head, int times) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (times--) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) {
            return head;
        }
        ListNode* left = head;
        ListNode* right;
        ListNode* res = NULL;
        ListNode* prevleft = NULL;
        while (true) {
            right = left;
            // swapPairs() me yaha 2 tha, ab k use ho raha hai
            int size = k;
            for (int i = 0; i < size - 1; i++) {
                if (right == NULL) {
                    break;
                }
                right = right->next;
            }

            if (right) {
                // Agle group ka starting node save karo
                ListNode* nextleft = right->next;
                reverse(left, size);
                if (prevleft) {
                    prevleft->next = right;
                }
                // Reverse ke baad current group ko next group se connect karo
                left->next = nextleft;
                prevleft = left;
                left = nextleft;
                if (res == NULL) {
                    res = right;
                }
            }
            else {
                // Remaining nodes ko as it is connect kar do
                if (prevleft) {
                    prevleft->next = left;
                }
                if (res == NULL) {
                    res = left;
                }
                break;
            }
        }
        return res;
    }
};

// Linked List print karne ka function
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Linked List: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    int k = 3;
    cout << "Original List : ";
    printList(head);
    Solution obj;
    head = obj.reverseKGroup(head, k);
    cout << "After Reversing in Groups of " << k << " : ";
    printList(head);
    return 0;
}