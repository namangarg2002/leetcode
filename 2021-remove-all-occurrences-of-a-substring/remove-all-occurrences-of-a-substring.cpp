class Solution {
public:

    void removeOccurenceRecursively(string &s, string &part){
        int found = s.find(part);
        if(found != string::npos){
            //part string has been located.
            // please remove it.
            string left_part = s.substr(0, found);
            string right_part = s.substr(found+part.size(), s.size());
            s = left_part + right_part; 
            removeOccurenceRecursively(s, part);
        }
        else{
            // base case
            // all the occurences of part has been removed from s
            return;
        }
    }
    string removeOccurrences(string s, string part) {

    //   while(s.find(part)!=string::npos){
    //     //   if inside loop, it means that part exists in a s(main) string
    //     s.erase(s.find(part), part.length());
    //   }
    //   return s;
    // }

        removeOccurenceRecursively(s, part);
        return s;
    }

};