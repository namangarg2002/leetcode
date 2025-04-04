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
    ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL){
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    ListNode* reverse(ListNode* prev, ListNode* curr){
        if(curr == NULL){
            return prev;
        }
        ListNode* next = curr->next;
        curr->next = prev;
        return reverse(curr, next);
    }
    bool compare(ListNode* &head1, ListNode* &head2){
        while(head1 != NULL && head2 != NULL){
            if(head1->val != head2->val){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* midNode = middleNode(head);
        ListNode* head2 = midNode->next;
        midNode->next = NULL;

        ListNode* prev = NULL;
        ListNode* curr = head2;
        head2 = reverse(prev, curr);

        bool ans = compare(head, head2);

        return ans;
    }
};