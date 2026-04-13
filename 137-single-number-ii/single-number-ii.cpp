class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mpp;

        for(int it:nums){
            mpp[it]++;
        }

        for(auto [num,count]:mpp){
            if(count == 1){
                return num;
            }
        }
        return -1;
    }
};