class Solution {
public:
    string minWindow(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        // invalid case
        if(len1 < len2){
            return "";
        }

        // valid case
        int start = 0;
        int ansIndex = -1;
        int ansLen = INT_MAX;

        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;
        // store freq of pattern string
        for(char ch: t){
            tMap[ch]++;
        }
        // initilaize count variable, that basically shows count of Actual  pattern  wale string K character present in the currewnt window
        int count = 0;
        for(int i=0; i<len1; i++){
            char ch = s[i];
            // update freqencies
            sMap[ch]++;
            if(sMap[ch] <= tMap[ch]){
                // valid character
                count++;
            }
            if(count == len2){
                // window found, jisme poora pattern exists karta hai
                // ->minimize
                // minimize usi case makarunga jis case mai 
                // s index pr jo characetr oresent hai wo 
                // yaa to extra hai ya faltu hai
                // aisa character jo patetrn ke ander hi nhi ha use remove karo
                while(sMap[s[start]]> tMap[s[start]] || tMap[s[start]] == 0){
                    if(sMap[s[start]] > tMap[s[start]]){
                        sMap[s[start]]--;
                    }
                    start++;
                }
                // answer nikalo
                int windowLength = i - start + 1;
                if(windowLength <  ansLen){
                    ansLen = windowLength;
                    ansIndex = start;
                } 
            }
        }
        if(ansIndex == -1){
            return "";
        }else{
            return s.substr(ansIndex, ansLen);
        }
    }
};