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
    void sanitizeMap(ListNode* curr, unordered_map<int,ListNode*>&mp, int csum){
        int temp = csum;
        while(curr){
            temp += curr->val;
            if(temp == csum) break;
            mp.erase(temp);
            curr = curr->next;
        }
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (!head) return nullptr;

        unordered_map<int, ListNode*> mp;
        ListNode* it = head;
        int csum = 0;
        ListNode dummy(0); 
        dummy.next = head;
        mp[0] = &dummy;  
        while (it) {
            csum += it->val;

            if (mp.find(csum) != mp.end()) {
                sanitizeMap(mp[csum]->next, mp, csum);
                mp[csum]->next = it->next;
            } else {
                mp[csum] = it; 
            }

            it = it->next;
        }

        return dummy.next;
    }
};