class Solution {
public:
    void backtrack(int ind,string& s,vector<string>& result,string& digits,vector<string>& ans){
        //Base condition
        if(ind == digits.size()){
            ans.push_back(s);
            return;
        }
        int digit = digits[ind] - '0';
        string letter = result[digit];
        for(int i = 0; i < letter.size(); i++){
            s.push_back(letter[i]);
           backtrack(ind+1,s,result,digits,ans);
           s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string s = "";
        vector<string> combo = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        backtrack(0,s,combo,digits,ans);
        return ans;
    }
};