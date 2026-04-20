class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int totalXOR = 0;
        for(int i=0; i<nums.size(); i++){
            totalXOR ^= nums[i];
        }
        int setbit = totalXOR & -(unsigned int)totalXOR;
        int n1 = 0;
        int n2 = 0;
        for(auto num : nums){
            if((num & setbit) != 0){
                n1 ^= num; 
            }
            else{
                n2 ^= num;
            }
        }
        return {n1,n2};
    }
};