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
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL) return true;
        queue<TreeNode*>q;
        q.push(root);
        bool nullFound = false;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front == NULL){
                // NULL Found
                nullFound = true;
            }else{
                if(nullFound) return false; //check if already NULL or not  if yes simply says NOT CBT
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
};