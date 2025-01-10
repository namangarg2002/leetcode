class Solution {
public:
    unordered_map<char, int> countFrequency(const string& str) {
    unordered_map<char, int> freq;
    for (char ch : str) {
        freq[ch]++;
    }
    return freq;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    unordered_map<char, int> maxFreq;
    for (const string& word : words2) {
        unordered_map<char, int> wordFreq = countFrequency(word);
        for (const auto& entry : wordFreq) {
            maxFreq[entry.first] = max(maxFreq[entry.first], entry.second);
        }
    }
    
    // Step 2: Check each word in words1
    vector<string> result;
    for (const string& word : words1) {
        unordered_map<char, int> wordFreq = countFrequency(word);
        bool isUniversal = true;
        
        // Step 3: Check if the word satisfies the conditions
        for (const auto& entry : maxFreq) {
            if (wordFreq[entry.first] < entry.second) {
                isUniversal = false;
                break;
            }
        }
        
        // If it satisfies, add it to the result
        if (isUniversal) {
            result.push_back(word);
        }
    }
    return result;
            
    }
};