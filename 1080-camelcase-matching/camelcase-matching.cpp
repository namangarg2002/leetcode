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
    
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c]) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }
    
    bool match(const string& query) {
        TrieNode* node = root;
        for( char c:query){
            if(node->children.count(c)){
                node = node->children[c];
                // if we reach the end of a valid pattern
                if(node->isEnd) return true;
            }else if(isupper(c)){
                // if the character is upper and not in the Trie, its invalid
                return false;
            }
        }
        return node->isEnd;
    }
};
class Solution {
    bool isMatch(const string& query, const string& pattern) {
        int i = 0;
        for (char c : query) {
            if (i < pattern.size() && c == pattern[i]) {
                i++;
            } else if (isupper(c)) {
                return false;
            }
        }
        return i == pattern.size();
    }
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        Trie trie;
        trie.insert(pattern);
        for(const string&query:queries){
            result.push_back(isMatch(query, pattern));
        }        
        return result;
    }
};