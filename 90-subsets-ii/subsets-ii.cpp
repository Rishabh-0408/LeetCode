class Solution {
public:
    void helper(int index,vector<int>& curr,vector<int>& nums, set<vector<int>>& ans){
        //Base condition
        if(index==nums.size()){
            ans.insert(curr);
            return;
        }
        //include
        curr.push_back(nums[index]);
        helper(index+1,curr,nums,ans);
        curr.pop_back();
        //exclude
        helper(index+1,curr,nums,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<int> curr;
        helper(0,curr,nums,ans);
        vector<vector<int>> result(ans.begin(), ans.end());
        return result;
    }
};