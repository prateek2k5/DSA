// Example 1:
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]

// Example 2:
// Input: head = [0,1,2], k = 4
// Output: [2,0,1]

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// ===============================
// Definition of List Node
// ===============================
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        // Empty list hai to wahi return kar do
        if (head == NULL)
            return head;
        // Last node aur length find karo
        ListNode *last = head;
        int n = 1;
        while (last->next != NULL)
        {
            n++;
            last = last->next;
        }

        // Extra rotations hata do
        k = k % n;
        // Rotation ki zarurat nahi hai
        if (k == 0)
            return head;

        // (n-k)th node tak jao (yahi break point hoga)
        ListNode *t = head;
        int count = 1;
        while (count < (n - k))
        {
            t = t->next;
            count++;
        }
        // List ko circular bana do
        last->next = head;
        // Break point ke next se new list start hogi
        ListNode *newHead = t->next;
        // Circle tod do
        t->next = NULL;
        return newHead;
    }
};

// ===============================
// Create Linked List
// ===============================
ListNode *createList(int arr[], int n)
{
    if (n == 0)
        return NULL;

    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;

    for (int i = 1; i < n; i++)
    {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// ===============================
// Print Linked List
// ===============================
void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// ===============================
// Main Function
// ===============================
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode *head = createList(arr, n);
    cout << "Original List: ";
    printList(head);
    int k = 2;
    Solution obj;
    head = obj.rotateRight(head, k);
    cout << "Rotated List: ";
    printList(head);
    return 0;
}