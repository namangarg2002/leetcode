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
    void solve(ListNode* head, int &carry){
        if(!head) return;
        solve(head->next, carry);
        // 1 case solve then recusion futher solve it.
        int prod = head->val * 2 + carry;
        head->val = prod % 10;
        carry = prod / 10;
    }

    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        solve(head, carry);

        if(carry > 0){
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }
        return head;
    }
};