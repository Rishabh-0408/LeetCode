class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalwater = 0;
        vector<int> LeftMax(n),RightMax(n);

        LeftMax[0] = height[0];
        for(int i = 1; i < n; i++){
            LeftMax[i] = max(LeftMax[i-1], height[i]);
        }
        RightMax[n-1] = height[n-1];
        for(int i = n-2; i >=0; i--){
            RightMax[i] = max(RightMax[i+1],height[i]);
        }
        for(int i = 0; i < n; i++){
            totalwater += min(LeftMax[i],RightMax[i]) - height[i];
        }
        return totalwater;
    }
};