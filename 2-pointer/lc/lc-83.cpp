// LeetCode 83: Remove Duplicates (linked list)
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// in LeetCode we don't free memory of the nodes, so we don't need to free memory in this implementation

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

/*    ListNode* deleteDuplicates(ListNode* head) {
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