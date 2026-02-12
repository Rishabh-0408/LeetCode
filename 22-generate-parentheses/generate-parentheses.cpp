class Solution {
public:
    void Back_track(string &curr, int n, int open, int close, vector<string>& Str) {
    if (curr.length() == 2 * n) {
        Str.push_back(curr);
        return;
    }
    if (open < n) {
        curr.push_back('(');        // DO (Action)
        Back_track(curr, n, open + 1, close, Str);
        curr.pop_back();            // UNDO (Backtrack)
    }
    if (close < open) {
        curr.push_back(')');        // DO
        Back_track(curr, n, open, close + 1, Str);
        curr.pop_back();            // UNDO
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string> Str;
        string curr = "";
        Back_track(curr, n, 0, 0, Str);
        return Str;
    }
};