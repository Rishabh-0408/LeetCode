class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int totalWater = 0;
        for(int i = 0; i < n; i++){
            while(!st.empty() && height[st.top()] < height[i]){
                // 1. BASE NIKALO (Gaddha)
                int base = st.top();
                st.pop();

                if(st.empty()){
                    break;
                }

                int leftPtr = st.top();

                int width = i - leftPtr - 1;

                int boundary_height = min(height[i],height[leftPtr]) - height[base];

                totalWater += width * boundary_height;
            }
            // Current building ko stack mein daal do aage ke calculations ke liye
            st.push(i);
        } 
        return totalWater;
    }
};