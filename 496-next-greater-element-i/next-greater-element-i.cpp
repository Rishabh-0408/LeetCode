class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        for(int i = 0; i < n1; i++){
            int curr_ele = nums1[i];
            int next_greater_ele = -1;
            bool found = false;
            for(int j = 0; j < n2; j++){
                if(nums2[j] == curr_ele){
                   found = true;
                }
                if(found && nums2[j] > curr_ele){
                    next_greater_ele = nums2[j];
                    break;
                }
            }
            ans.push_back(next_greater_ele);
        }
        return ans;
    }
};