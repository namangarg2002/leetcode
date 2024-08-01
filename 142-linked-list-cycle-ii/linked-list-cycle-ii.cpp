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
    ListNode *detectCycle(ListNode *head) {
        // check for loop
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
            if (fast == slow)
            {
                break;
            }
        }
        if(fast == NULL){
            // ṇo cycle present
            return NULL;
        }
        // yaha pahuncha iska matlb loop present hai LL mai i.e., slow or fast meet kar gaye hai
        slow = head;

        // slow and fast 1-1 step move karenge
        while (fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        // return starting point
        return slow;
        
        }
};