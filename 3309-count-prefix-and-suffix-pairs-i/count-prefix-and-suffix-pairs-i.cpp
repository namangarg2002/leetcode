class Solution {
public:
    bool checkFind(string &str1, string &str2){
        if(str1.length() <= str2.length() && str2.find(str1)==0 && str2.rfind(str1)==str2.length() - str1.length()){
            return true;
        }else{
            return false;
        }
    }

    bool checkSubString(string &str1, string &str2){
        int m = str1.length();
        if(str1.length() <= str2.length() && str2.substr(0, m) == str1 && str2.substr(str2.length() - str1.length(), m) == str1){
            return true;
        }else{
            return false;
        }
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                string str1 = words[i];
                string str2 = words[j];

                // if(checkFind(str1, str2)){
                //     count++;
                // }

                if(checkSubString(str1, str2)){
                    count++;
                }
            }
        }
        return count;
    }
};