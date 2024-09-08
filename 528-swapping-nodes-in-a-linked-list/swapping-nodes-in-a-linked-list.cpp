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
    int Len(ListNode* head){
        if(!head) return 0;
        return 1 + Len(head->next);
    }
    ListNode* swapNodes(ListNode* head, int k) {

        int len = Len(head);
        int lpos = k;
        int rpos = len - k + 1;

        if(lpos > rpos) swap(lpos, rpos);

        // Case 1:
        if(!head || !head->next) return head;

        // Case 2:
        if(lpos==rpos) return head;

        // Case 3:
        if(len==2){
            ListNode* nxtNode = head->next;
            nxtNode->next = head;
            head->next = NULL;
            head = nxtNode;
            return head;
        }

        // Case4:
        if(lpos == 1){
            ListNode* lp = NULL;
            ListNode* ln = head;
            ListNode* rp = head;
            for(int i=0; i<rpos-2; i++){
                rp = rp->next;
            }
            ListNode* rn = rp->next;
            ListNode* rsave = rn->next;

            // swapping
            rn->next = ln->next;
            rp->next = ln;
            ln->next = rsave;
            head = rn;
            return head;
        }

        // Case 5:
        int noOfNodesBetweenSwappingNodes = rpos - lpos - 1;

        if (noOfNodesBetweenSwappingNodes == 0){
            ListNode* lp = head;
            for(int i=0; i<lpos-2; i++){
                lp = lp->next;
            }
            ListNode* ln = lp->next;

            ListNode* rp = head;
            for(int i=0; i<rpos-2; i++){
                rp = rp->next;
            }
            ListNode* rn = rp->next;
            
            ListNode* rsave = rn->next;

            // Swapping 
            lp->next = rp->next;
            rn->next = rp;
            rp->next = rsave;

            return head;
        }else{
            // no. of nodes between swap nodes >= 1

            ListNode* lp = head;
            for(int i=0; i<lpos-2; i++){
                lp = lp->next;
            }
            ListNode* ln = lp->next;

            ListNode* rp = head;
            for(int i=0; i<rpos-2; i++){
                rp = rp->next;
            }
            ListNode* rn = rp->next;
            
            ListNode* rsave = rn->next;

            // swapping
            lp->next = rn;
            rn->next = ln->next;
            rp->next = ln;
            ln->next = rsave;
            return head;
        }

    }
};