class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> maxPerWindow;
        deque<int> dq;
        int start=0;
        int end=0;
        for(;end<nums.size();end++){

            //updation
            while(!dq.empty() && nums[dq.back()] <= nums[end]){
                dq.pop_back();
            }
            dq.push_back(end);

            //invalidation
            if((end-start+1) < k){
                continue;
            }
            while(!dq.empty() && dq.front() < (end - k + 1)){
                dq.pop_front();
            }

            //answer compute
            maxPerWindow.push_back(nums[dq.front()]);
            start++;

        }

        return maxPerWindow;

    }
};