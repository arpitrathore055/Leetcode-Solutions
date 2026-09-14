class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        int n=nums.size();
        
        int start=0;
        int end=0;
        int maxFrequency=0;
        long long currSum=0;
        
        for(;end<n;++end){
            
            // updation
            currSum+=nums[end];
            int windowSize=end-start+1;
            
            // invalidation
            while(((long long)windowSize*nums[end])-currSum > k){
                
                currSum-=nums[start];
                start++;
                windowSize=end-start+1;
                
            }
            
            // answer compute
            maxFrequency=max(maxFrequency,windowSize);
            
        }
        
        return maxFrequency;
    }
};