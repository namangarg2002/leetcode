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
    // int getLength(ListNode* head){
    //     ListNode* temp = head;
    //     int count = 0;
    //     while(temp != NULL){
    //         count++;
    //         temp = temp->next;
    //     }
    //     return count;
    // }
    ListNode* middleNode(ListNode* head) {
        // int n = getLength(head);
        // int position = n/2 + 1;
        // int currPos = 1;
        // ListNode *temp = head;
        // while(currPos != position){
        //     currPos++;
        //     temp = temp->next;
        // }
        // return temp;

        // Tortoise ALgorithm
        ListNode* slow = head; 
        ListNode* fast = head;
        while(fast != NULL){
            fast = fast->next; // fast ne yaha tk 1 step chal liya h
            if(fast != NULL){
                fast = fast->next;
                // yaha tk fast ne 2 step chl liye h.

                // ab slow ko bhi chl walo 1 step
                slow = slow->next;
            }
        }
        return slow;                                    
    }
};