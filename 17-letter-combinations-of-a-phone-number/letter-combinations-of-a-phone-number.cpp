class Solution {
public:
    void solve(string mapping[], string output, int index, vector<string>&ans, string str){
        // base case
        if(index >= str.length()){
            cout<<"Inside Base case"<<endl;
            // output me strign bn chuki hogi
            // store that string in ans array
            if(output.length() > 0){
                ans.push_back(output);
            }
            return;
        }
        string temp = mapping[str[index]-'0'];
        cout<<"Printing temp: "<<temp<<endl;
        for(auto ch:temp){
            output.push_back(ch);
            cout<<"Inserting "<<ch<<" In output: "<<output<<endl;
            solve(mapping, output, index+1, ans, str);
            // backtracking concept
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string mapping[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string output = "";
        int index = 0;
        vector<string>ans;
        solve(mapping, output, index, ans, digits);
        return ans;
    }
};