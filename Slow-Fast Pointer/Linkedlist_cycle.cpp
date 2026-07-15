#include<bits/stdc++.h>
#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
            return false;
        if (head->next == nullptr)
            return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }
        return false;
    }
};

int main() {
    // Creating linked list:
    // 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    // Create cycle
    // Last node points to node with value 2
    head->next->next->next->next = head->next;
    Solution obj;
    if (obj.hasCycle(head))
        cout << "Cycle Found" << endl;
    else
        cout << "No Cycle Found" << endl;

    return 0;
}