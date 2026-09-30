// LeetCode 83: Remove Duplicates (linked list)
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// in LeetCode we don't free memory of the nodes, so we don't need to free memory in this implementation
// Time Complexity: O(N)
// Space Complexity: O(1)
#include "../../using.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

/*  solving using one pointer
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            
            if (current->val == current->next->val) {
                // if values are equal, skip the next node
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        return head;
    }
*/
    // solving using two pointers
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == nullptr) {
            return head;
        }

        ListNode* current = head;
        ListNode* nextNode = head->next;

        while (nextNode != nullptr) {
            // case-1: current node value is equal to next node value
            if (current->val == nextNode->val) {
                // if values are equal, skip the next node
                current->next = nextNode->next;
                nextNode = nextNode->next;
            } else { // case-2: current node value is not equal to next node value
                current = nextNode;
                nextNode = nextNode->next;
            }
        }
        return head;
    }
};

/*
Complexity Calculation:
- Time Complexity: O(N)
  - nextNode pointer visits every node in the singly-linked list from head to tail exactly once.
  - Node comparison and pointer rewiring (current->next = nextNode->next) operate in O(1) time.
  - Total Time = O(N), where N is number of nodes in list.

- Space Complexity: O(1)
  - Modifies the existing linked list pointers in-place.
  - Only uses two pointer references (current, nextNode).
  - No new nodes allocated -> Auxiliary Space = O(1).
*/