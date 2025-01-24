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
    int solve(TreeNode*root){
        if(!root) return 0;

        int robThisHouse = 0;
        int dontRobThisHouse = 0;

        // 1 case solution
        // rob current house
        robThisHouse += root->val;
        if(root->left){
            robThisHouse += solve(root->left->left) + solve(root->left->right);
        }
        if(root->right){
            robThisHouse += solve(root->right->left) + solve(root->right->right);
        }

        // dont rob Current House 
        dontRobThisHouse += solve(root->left) + solve(root->right);

        return max(robThisHouse, dontRobThisHouse);

    }

    int solveMem(TreeNode*root, unordered_map<TreeNode* , int>&dp){
        if(!root) return 0;

        if(dp.find(root) != dp.end()) return dp[root];

        int robThisHouse = 0;
        int dontRobThisHouse = 0;

        // 1 case solution
        // rob current house
        robThisHouse += root->val;
        if(root->left){
            robThisHouse += solveMem(root->left->left, dp) + solveMem(root->left->right, dp);
        }
        if(root->right){
            robThisHouse += solveMem(root->right->left, dp) + solveMem(root->right->right, dp);
        }

        // dont rob Current House 
        dontRobThisHouse += solveMem(root->left, dp) + solveMem(root->right, dp);

        dp[root] = max(robThisHouse, dontRobThisHouse);
        return dp[root];
    }
    int rob(TreeNode* root) {
        // // Recursive Approach
        // return solve(root);

        // Memoiation Approach
        unordered_map<TreeNode* , int>dp;
        return solveMem(root, dp);
    }
};