#include<bits/stdc++.h>
#include <iostream>
using namespace std;

// Linked List ka node
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
    ListNode* reverseList(ListNode* head) {
        // curr -> current node ko traverse karega
        // prev -> reversed list ka previous node store karega
        ListNode* curr = head;
        ListNode* prev = NULL;
        // Jab tak list khatam na ho
        while (curr != NULL) {
            // Agla node save kar lo, warna link toot jayega
            ListNode* next = curr->next;
            // Current node ka pointer reverse karo
            curr->next = prev;
            // prev aur curr ko ek step aage badhao
            prev = curr;
            curr = next;
        }
        // Reverse hone ke baad prev hi naya head hoga
        return prev;
    }
};

// Linked List print karne ke liye
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Linked List: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout << "Original List: ";
    printList(head);
    Solution obj;
    head = obj.reverseList(head);
    cout << "Reversed List: ";
    printList(head);
    return 0;
}