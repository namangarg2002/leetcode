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
    ListNode* reverseUsingRecursion( ListNode* prev,ListNode* curr){
        // base case
        if(curr == NULL){
            return prev;
        }
        // 1 case we have solve next recursion will handle it
        ListNode* nextNode = curr->next;
        curr->next = prev;
        return reverseUsingRecursion(curr, nextNode);

    }
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        // while(curr != NULL){
        //     ListNode *next = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = next;
        // }
        // return prev;

        return reverseUsingRecursion(prev, curr);

    }
};