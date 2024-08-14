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
    ListNode*findMid(ListNode* head){
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast->next != NULL){
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    ListNode*merge(ListNode* left, ListNode* right){
        if(left == NULL) return right;
        if(right == NULL) return left;

        ListNode*ans = new ListNode(-1);
        ListNode*mptr = ans;

        while(left && right){
            if(left->val <= right->val){
                mptr->next = left;
                mptr = left;
                left = left->next;
            }else{
                mptr->next = right;
                mptr = right;
                right = right->next;
            }
        }
        if(left){
            mptr->next = left;
        }else{
            mptr->next = right;
        }
        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        // Break LL intot two halves using mid node;
        ListNode*mid = findMid(head); 

        ListNode*left = head;
        ListNode*right = mid->next;
        mid->next = NULL; // for making two differnrt LL i.e., Left and Right

        // sort RE
        left = sortList(left);
        right = sortList(right);

        // merge both Left and Right LL
        ListNode*mergedLL = merge(left, right);
        return mergedLL;
    }
};