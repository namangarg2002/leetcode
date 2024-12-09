/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void storeInOrder(TreeNode* root, vector<int> &inOrder){
        // base case
        if(root == NULL){
            return;
        }
        // LNR
        // L
        storeInOrder(root->left, inOrder);
        // N
        inOrder.push_back(root->val);
        // R
        storeInOrder(root->right, inOrder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inOrder;
        storeInOrder(root, inOrder);

        // find target using 2 pointer approach
        int s = 0; 
        int e = inOrder.size()-1;
        while(s < e){
            int sum = inOrder[s] + inOrder[e];
            if(sum == k){
                return true;
            }else if(sum < k){
                s++;
            }else if(sum > k){
                e--;
            }
        }
        return false;
    }
};