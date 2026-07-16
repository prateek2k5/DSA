#include<bits/stdc++.h>
#include <iostream>
using namespace std;

// Definition of ListNode
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Agar list empty hai ya reverse karne ki zarurat nahi hai
        if (head == NULL || left == right)
            return head;
        ListNode* t = head;       // Left position tak traverse karega
        ListNode* before = NULL;  // Left se pehle wala node
        int pos = 1;
        // Left position tak pahucho
        while (pos < left) {
            before = t;
            t = t->next;
            pos++;
        }
        // Reverse process start
        ListNode* curr = t;
        ListNode* prev = NULL;
        int times = right - left + 1;
        while (times--) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // Reversed part ko remaining list se connect karo
        t->next = curr;
        // Agar reverse head se start nahi hua
        if (before) {
            before->next = prev;
            return head;
        }
        // Agar reverse head se start hua
        return prev;
    }
};
// Linked List print karne ke liye
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
    // Linked List: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout << "Original List: ";
    printList(head);
    int left = 2;
    int right = 4;
    Solution obj;
    head = obj.reverseBetween(head, left, right);
    cout << "Reversed Between " << left << " and " << right << ": ";
    printList(head);
    return 0;
}