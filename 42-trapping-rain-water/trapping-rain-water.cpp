class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;
        int leftPtr = 0, rightPtr = n-1;
        int leftMax = 0, rightMax = 0;
        while(leftPtr <= rightPtr){
            if(height[leftPtr] <= height[rightPtr]){
                if(height[leftPtr] > leftMax){
                    leftMax = height[leftPtr];
                }
                else{
                    totalWater += leftMax - height[leftPtr];
                }
                leftPtr++;
            }
            else{
               if(height[rightPtr] <= height[leftPtr]){
                    if(height[rightPtr] > rightMax){
                        rightMax = height[rightPtr];
                    }
                    else{
                        totalWater += rightMax - height[rightPtr]; 
                    }
                    rightPtr--;
                }
            }
        }
        return totalWater;
    }
};