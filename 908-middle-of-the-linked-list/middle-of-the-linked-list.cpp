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
    int getLength(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* middleNode(ListNode* head) {
        int size = getLength(head);
        int position = size/2 + 1;
        int currPosition = 1;
        ListNode* temp = head;
        while(currPosition != position){
            temp = temp->next;
            currPosition++;
        }
        return temp;


        return head;
    }
};