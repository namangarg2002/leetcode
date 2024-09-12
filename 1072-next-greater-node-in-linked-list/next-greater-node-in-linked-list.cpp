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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;

        // step 1 : traverse LL and store values in the vactor
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        // step 2: Use tat stack to find the next greater eleemnt
        int n = arr.size();
        vector<int> ans(n,0);
        stack<int> st;

        for(int i= n-1; i>=0; i--){
            int curr = arr[i];
            while(!st.empty() && arr[st.top()]<=curr){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = arr[st.top()];
            }
            st.push(i);
        }
        return ans;
        
    }
};