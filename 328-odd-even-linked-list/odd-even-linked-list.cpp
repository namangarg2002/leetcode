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
    ListNode* oddEvenList(ListNode* head) {
      if(!head || head->next == NULL) return head;

      ListNode* h1 = head; // odd index list
      ListNode* h2 = head->next; // even index List
      ListNode* evenHead = h2;
      while(h2 && h2->next){
        h1->next = h2->next;
        h2->next = h2->next->next;

        h1 = h1->next;
        h2 = h2->next;
      }
        // the two indepeddent prepared list has beeen grouped
      h1->next = evenHead;
      return head;
    }
};