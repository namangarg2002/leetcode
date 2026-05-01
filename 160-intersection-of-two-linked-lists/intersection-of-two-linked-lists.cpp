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
    int getLength(ListNode* &head){
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* traversalLL(ListNode* &a, ListNode* &b){
        while(a != b){
            a = a->next;
            b = b->next;
        }
        return a;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int List1Lenght = getLength(headA);
        int List2Lenght = getLength(headB);

        if(List2Lenght > List1Lenght){
            int diff = List2Lenght - List1Lenght;
            for(int i=0; i<diff; i++){
                headB = headB->next;
            }

            return traversalLL(headA, headB);
        }else{
            int diff = List1Lenght - List2Lenght;
            for(int i=0; i<diff; i++){
                headA = headA->next;
            }

            return traversalLL(headA, headB);
        }

    }
};