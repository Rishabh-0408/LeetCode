class Solution {
public:
    void backtrack(int index, int num, int sum, vector<int>& current,vector<vector<int>>& ans){
        if(sum==0 && current.size()==num){
            ans.push_back(current);
            return;
        }
        if(sum <=0 || current.size() > num){
            return;
        }
        for(int i = index; i <= 9; i++){
            if(i<=sum){
                current.push_back(i);
                backtrack(i+1,num,sum-i,current,ans);
                current.pop_back();
            }
            else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(1,k,n,current,ans);
        return ans;
    }
};