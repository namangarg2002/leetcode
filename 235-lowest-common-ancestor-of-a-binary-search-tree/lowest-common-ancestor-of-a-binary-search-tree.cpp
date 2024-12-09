/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root == NULL){
            return NULL;
        }
        // Case1: p and q both comes in left subtree of root node
        if(p->val < root->val && q->val < root->val){
            TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
            return leftAns;
        }
        // Case2: p and q both comes in right subtree of root node
        if(p->val > root->val && q->val > root->val){
            TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
            return rightAns;
        }
        // Case3: p is in left subtree of root node && q is on right subtree of root node
        if(p->val < root->val && q->val > root->val){
            return root;
        }
        // Case4: p is in right subtree of root node && q is on left subtree of root node
        if(p->val > root->val && q->val < root->val){
            return root;
        }
        return root;
        
    }
};