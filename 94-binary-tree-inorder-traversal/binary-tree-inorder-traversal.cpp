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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode*curr = root;
        while(curr){
            // left node is NULL, then Visited and go right
            if(curr->left == nullptr){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                // left node is NOT NULL

                // find InOrder Predecessor
                TreeNode*pred = curr->left;
                while(pred->right != curr && pred->right){
                    pred=pred->right;
                }
                // if pred right node is NULL, then , go left after establishing link from predecessor to curr
                if(pred->right == nullptr){
                    pred->right = curr;
                    curr=curr->left;
                }
                else{
                    // left is already visited, Go right after visiting curr node while removing link
                    pred->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};