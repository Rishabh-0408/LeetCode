class Solution {
public:
    void Back_track(string curr,int n,int open,int close,vector<string>& Str){
        if(curr.length() == 2*n){
            Str.push_back(curr);
            return;
        }
        if(open<n) Back_track(curr+'(',n,open+1,close,Str);
        if(close<open) Back_track(curr+')',n,open,close+1,Str);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> Str;
        Back_track("", n, 0, 0, Str);
        return Str;
    }
};