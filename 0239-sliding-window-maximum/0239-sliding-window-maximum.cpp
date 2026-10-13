class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  
        int n=nums.size();
        vector<int> maxPerWindow;
        int start=0;
        int end=0;
        
        deque<int> dq;
        
        for(;end<n;end++){
            
            //updation part
            //remove all smaller elements than current element from deque
            while(!dq.empty() && nums[dq.back()] <= nums[end]){
                dq.pop_back();
            }
            dq.push_back(end);
            
            if((end-start+1) < k){
                continue;
            }
            
            //invalidation
            while(!dq.empty() && dq.front() < (end-k+1)){
                dq.pop_front();
            }
            
            //answer computation
            maxPerWindow.push_back(nums[dq.front()]);
            start++;
            
        }
        
        return maxPerWindow;
    }
};