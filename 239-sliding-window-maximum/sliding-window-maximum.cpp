class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n =  nums.size();
        vector<int> ans;
        deque<int> dequeue;
        for(int i=0; i<n; i++){
            if(!dequeue.empty() && dequeue.front() <= i-k){
                dequeue.pop_front();
            }
            while(!dequeue.empty() && nums[dequeue.back()] <= nums[i]){
                dequeue.pop_back();
            }
            dequeue.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[dequeue.front()]);
            }
        }
        return ans;
    }
};