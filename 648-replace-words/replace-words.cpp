class Trie {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEnd = false;
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c]) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }
    
    string findShortestRoot(string word) {
        TrieNode* node = root;
        string prefix;
        for (char c : word) {
            if (!node->children[c]) {
                return ""; 
            }
            prefix += c;
            node = node->children[c];
            if (node->isEnd) {
                return prefix;
            }
        }
        return "";
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;

        // insert dictionary into Trie
        for(auto root: dictionary){
            trie.insert(root);
        }
        stringstream ss(sentence);
        string word;
        string ans;

        // Process each word in the sentence
        while (ss >> word) {
            string root = trie.findShortestRoot(word);
            if (!root.empty()) {
                ans += root;
            } else {
                ans += word;
            }
            ans += " ";
        }

        if (!ans.empty()) {
            ans.pop_back(); // Remove the trailing space
        }

        return ans;
        
    }
};