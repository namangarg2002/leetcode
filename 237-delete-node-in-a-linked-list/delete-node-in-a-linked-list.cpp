/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {

        ListNode* curr = node;
        ListNode* next = node->next;

        curr->val = next->val;
        curr->next = next->next;
        next->next = NULL;
        delete next;
    }
};