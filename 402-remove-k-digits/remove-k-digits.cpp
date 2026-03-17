class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        if(k >= num.length()){
            return "0";
        }
        for(char c : num){
            while(!res.empty() && res.back() > c && k > 0)
            {
                res.pop_back();
                k--;
            }
            if(!res.empty() || c != '0')
            {
                res.push_back(c);
            }
        }
        // Edge Case: If the array was completely monotonically increasing (e.g., "12345" and k=2)
        // We still have k > 0, so remove from the end (the largest numbers)
        while (!res.empty() && k > 0) {
            res.pop_back();
            k--;
        }

        return res.empty() ? "0" : res;
    }
};