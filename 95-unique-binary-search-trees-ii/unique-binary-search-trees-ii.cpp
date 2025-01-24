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
    vector<TreeNode*> allPossibleBST(int start, int end){
        // Base Case
        if(start > end) return {NULL};
        if(start == end) return {new TreeNode(start)};
        vector<TreeNode*>ans;
        for(int i=start; i<=end; i++){
            vector<TreeNode*> left = allPossibleBST(start, i-1);
            vector<TreeNode*> right = allPossibleBST(i+1, end); 

            for(int j=0; j<left.size(); j++){
                for(int k=0; k<right.size(); k++){
                    TreeNode*root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> allPossibleBSTMem(int start, int end, vector<vector<vector<TreeNode*>>>& dp){
        // Base Case
        if(start > end) return {nullptr};
        if(start == end) return {new TreeNode(start)};

        if(!dp[start][end].empty()){
            return dp[start][end];
        }
        vector<TreeNode*>ans;
        for(int i=start; i<=end; i++){
            vector<TreeNode*> left = allPossibleBSTMem(start, i-1, dp);
            vector<TreeNode*> right = allPossibleBSTMem(i+1, end, dp); 

            for(int j=0; j<left.size(); j++){
                for(int k=0; k<right.size(); k++){
                    TreeNode*root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        dp[start][end] = ans;
        return dp[start][end];
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        // // Recursive Approach
        // return allPossibleBST(1, n);

        // Memoiation Aproach
        vector<vector<vector<TreeNode*>>> dp(n + 1, vector<vector<TreeNode*>>(n + 1));
        return allPossibleBSTMem(1, n, dp);
    }
};