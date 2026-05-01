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
    ListNode* findMiddleNode(ListNode* &head){
        if(head->next == NULL) return head;
        
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
    ListNode* reverseList(ListNode* &prev, ListNode* &curr){
        if(curr == NULL) return prev;
        ListNode* nextNode = curr->next;
        curr->next = prev;
        return reverseList(curr, nextNode);
    }
    bool compare(ListNode* &head1, ListNode* &head2){
        while(head1 != NULL && head2 != NULL){
            if(head1->val != head2->val){
                return false;
            }else{
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* middleNode = findMiddleNode(head);
        
        ListNode* firstList = head;
        ListNode* secondList = middleNode->next;
        middleNode->next = NULL;
        
        ListNode* prev = NULL;
        ListNode* curr = secondList;
        secondList = reverseList(prev, curr);
        
        return compare(firstList, secondList);
    }
};