class TrieNode
{
public:
  char value;
  TrieNode *children[26];
  bool isTerminal;
  int childCount;

  TrieNode(char val)
  {
    this->value = val;
    for (int i = 0; i < 26; i++)
    {
      children[i] = NULL;
    }
    this->isTerminal = false;
    this->childCount = 0;
  }
};
class Solution {
public:
    void insertWord(TrieNode *root, string word, int index = 0)
    {
        if (index == word.length())
        {
            root->isTerminal = true;
            return;
        }
        char ch = word[index];
        int childindex = ch - 'a';
        TrieNode *child;
        if (root->children[childindex] != NULL)
        {
            // child present
            child = root->children[childindex];
        }
        else
        {
            // absent
            child = new TrieNode(ch);
            root->children[childindex] = child;
            root->childCount++;
        }
        // recurssion will handle further
        insertWord(child, word, index + 1);
    }

    void findLCP(string &ans, TrieNode* root){
        // base case
        if(root->isTerminal == true){
            return;
        }

        TrieNode* child;
        // abhi root node par hu
        if(root->childCount == 1){
            // child tak jaao
            for(int i=0; i<26; i++){
                if(root->children[i] != NULL){
                    child = root->children[i];
                }
            }
            // ans mai store karwao
            ans.push_back(child->value);
        }else{
            return;
        }
        // rest recurssion will handle it
        findLCP(ans, child);
    }
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');
        // insert all strings
        for(auto str: strs){
            insertWord(root, str);
        }
        string ans = "";
        // string str = strs[0];
        findLCP(ans, root);
        return ans;
    }
};