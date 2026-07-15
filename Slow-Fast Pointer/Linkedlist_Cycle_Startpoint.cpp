#include<bits/stdc++.h>
#include <iostream>
using namespace std;
// Definition for singly-linked list
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
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // Detect cycle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // Move head and slow one step at a time
                while (head != slow) {
                    head = head->next;
                    slow = slow->next;
                }
                return head;
            }
        }
        return nullptr;
    }
};

int main() {

    // Create linked list:
    // 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    // Create cycle:
    // Last node (-4) points to node with value 2
    head->next->next->next->next = head->next;
    Solution obj;
    ListNode* start = obj.detectCycle(head);
    if (start != nullptr)
        cout << "Cycle starts at node with value: " << start->val << endl;
    else
        cout << "No cycle found." << endl;
    return 0;
}