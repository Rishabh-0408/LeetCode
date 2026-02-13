class Solution {
public:
    void helper(int index,vector<int>& curr,vector<int>& nums, vector<vector<int>>& ans){
        ans.push_back(curr);
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]) continue;

        //include
        curr.push_back(nums[i]);
        helper(i+1,curr,nums,ans);
        //backtrack
        curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0,curr,nums,ans);
        return ans;
    }
};