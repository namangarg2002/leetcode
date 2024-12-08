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
    vector<TreeNode* >ans;
    unordered_map<string, int>subTreeMap;
    string preOrderTraversal(TreeNode* root){
        if(!root) return "N";

        string curr = to_string(root->val);
        string fromLeft = preOrderTraversal(root->left);
        string fromRight = preOrderTraversal(root->right);

        string str = curr + "," + fromLeft + "," + fromRight;

        if(subTreeMap.find(str) != subTreeMap.end()){
            if(subTreeMap[str] == 1){
                ans.push_back(root);
            }
            subTreeMap[str]++;
        }else{
            subTreeMap[str] = 1;
        }
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preOrderTraversal(root);
        return ans;
    }
};