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
    bool hasCycle(ListNode *head) {
        // Through Mapping 
        // unordered_map<ListNode* , bool>mp;
        // ListNode* temp = head;
        // while(temp != NULL){
        //     if(mp[temp] == false){
        //         mp[temp] = true;
        //     }else{
        //         return true;
        //     }
        //     temp = temp->next;
        // }
        // return false;

        // Tortoise Algorithm
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};