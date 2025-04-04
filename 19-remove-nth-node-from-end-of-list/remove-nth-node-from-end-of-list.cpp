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
    int getSize(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = getSize(head);
        ListNode* prevNode = NULL;
        ListNode* currNode = head;
        int currentPos = 1;
        int PositionToBeRemoved = size - n + 1;
        if(PositionToBeRemoved == 1){
            // delete from head
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        while(currentPos < PositionToBeRemoved && currNode != NULL){
            prevNode = currNode;
            currNode = currNode->next;
            currentPos++;
        }

        if (currNode == NULL) return head;
        prevNode->next = currNode->next;
        delete currNode;

        return head;

    }
};