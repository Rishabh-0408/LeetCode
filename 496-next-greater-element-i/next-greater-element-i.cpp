class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(10001, -1);
        stack<int> st;
        for(int i = nums2.size()-1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }

            if(st.empty()) ans[nums2[i]] = -1;
            else ans[nums2[i]] = st.top();

            st.push(nums2[i]);
        }
        vector<int> correct_ans;
        for(int i = 0; i < nums1.size(); i++){
            correct_ans.push_back(ans[nums1[i]]);
        }
        return correct_ans;
    }
};