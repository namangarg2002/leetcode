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
    // int height(TreeNode* root){
    //     if(root == NULL){
    //        return true; 
    //     }
    //     int leftHeight = height(root->left);
    //     int rightHeight = height(root->right);
    //     int finalAns = max(leftHeight, rightHeight) + 1;
    //     return finalAns;
    // }
    // bool isBalanced(TreeNode* root) {
    //     // base case
    //     if(root == NULL){
    //         return true;
    //     }

    //     // currNode = solve
    //     int leftHeight = height(root->left);
    //     int rightHeight = height(root->right);

    //     int diff = abs(leftHeight-rightHeight);

    //     bool currNodeAns = (diff <= 1);

    //     int leftAns = isBalanced(root->left);
    //     int rightAns = isBalanced(root->right);

    //     if(currNodeAns && leftAns && rightAns){
    //         return true;
    //     }
    //     else{
    //         return false;
    //     }
    // }
    bool isbalanced = true;
    int height(TreeNode* root){
        if(!root) return 0;

        int left = height(root->left);
        int right = height(root->right);

        //check for current Node, is balanced or not
        if(isbalanced && abs(left - right)>1){
            isbalanced = false;
        }

        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root){
        height(root);
        return isbalanced;
    }

};