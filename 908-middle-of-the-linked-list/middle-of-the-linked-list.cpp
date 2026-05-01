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
    int getLength(ListNode* &head){
        if(head == NULL) return 0;
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* middleNode(ListNode* head) {
        if(head->next == NULL) return head;

        int length = getLength(head);
        int middleIndex = length/2;
        ListNode* prev = NULL;
        ListNode* curr = head;
        int currNodeIndex = 0;
        while(currNodeIndex < middleIndex){
            prev = curr;
            curr = curr->next;
            currNodeIndex++;
        }

        return curr;
    }
};