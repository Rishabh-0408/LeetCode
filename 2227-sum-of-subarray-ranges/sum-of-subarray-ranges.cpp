class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i=0; i<n; i++){
            int Max_val = INT_MIN;
            int Min_val = INT_MAX;
            for(int j=i; j<n; j++){
                Max_val = max(Max_val,nums[j]);
                Min_val = min(Min_val,nums[j]);
                sum += (Max_val - Min_val); 
            }
        } 
        return sum;
    }
};