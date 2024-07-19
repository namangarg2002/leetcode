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
        ListNode *slow = head;
        ListNode *fast = head;
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
        ListNode* nextNode = curr->next;
        curr->next = prev;
        return reverse(curr, nextNode);
    }
    bool compareList(ListNode* &head1, ListNode* &head2){
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
        //Step 1: break into 2 halves
        ListNode* midNode = middleNode(head);
        ListNode* head2 = midNode->next;
        midNode->next = NULL;

        // Step 2: revere second half
        ListNode* prev = NULL;
        ListNode* curr = head2;
        head2 = reverse(prev, curr);

        // Step 3: compare both halves i.e,. first half and revesed second half
        bool ans = compareList(head, head2);
        return ans;
    }
};