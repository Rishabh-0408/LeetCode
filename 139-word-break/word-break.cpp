class Solution {
public:
    bool solve(int index,string& s, unordered_set<string>& str, vector<int>& memo){
        if(index==s.size()){
            return true;
        }
        if (memo[index] != -1) return memo[index];
        string temp = "";
        for(int i = index; i < s.size(); i++){
            temp += s[i];
            if(str.find(temp) != str.end()){
                if(solve(i+1, s, str, memo)==true){
                    return memo[index] = 1;
                }                
            }
        }
        return memo[index] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> str(wordDict.begin(),wordDict.end());
        vector<int> memo(s.size(), -1);
        return solve(0, s, str, memo);
    }
};