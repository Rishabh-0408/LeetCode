class Solution {
public:
    void helper(int index,vector<int>& curr,vector<int>& nums,vector<vector<int>>& ans){
        //Base condition
        if(index == nums.size()){
            ans.push_back(curr);
            return;
        }
        //Include
        curr.push_back(nums[index]);
        helper(index+1, curr, nums, ans);
        curr.pop_back();
        //Exclude
        helper(index+1, curr,nums, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0,curr,nums,ans);
        return ans;
    }
};