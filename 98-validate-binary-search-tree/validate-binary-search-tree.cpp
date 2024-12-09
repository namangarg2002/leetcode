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
    // TreeNode* minValue(TreeNode* root){
    //     if(root == NULL){
    //         return NULL;
    //     }
    //     TreeNode* temp = root;
    //     while(temp->left != NULL){
    //         temp = temp->left;
    //     }
    //     return temp;
    // }
    // TreeNode* maxValue(TreeNode* root){
    //     if(root == NULL){
    //         return NULL;
    //     }
    //     TreeNode* temp = root;
    //     while(temp->right != NULL){
    //         temp = temp->right;
    //     }
    //     return temp;
    // }
    bool solve(TreeNode* root, long long lowerBound, long long upperBound){
        // base Case
        if(root == NULL){
            return true;
        }
        bool cond1 = (root->val > lowerBound);
        bool cond2 = (root->val < upperBound);
        bool leftAns = solve(root->left,lowerBound,root->val);
        bool rightAns = solve(root->right,root->val,upperBound);

        return (cond1 && cond2 && leftAns && rightAns);
        
    }

    bool isValidBST(TreeNode* root) {
        long long lowerBound = (long long)INT_MIN - 1;
        long long upperBound = (long long)INT_MAX + 1;

        return solve(root, lowerBound, upperBound);

    }
};