class Solution {
public:
    
    int subWithAtMostXDistinct(vector<int>& nums,int k){
        
        unordered_map<int,int> freqMap;
        int n=nums.size();
        
        int start=0;
        int end=0;
        int countSubarrays=0;
        int distIntegers=0;
        
        for(;end<n;++end){
            
            //updation
            if(++freqMap[nums[end]] == 1){
                distIntegers++;
            }
            
            //invalidation
            while(distIntegers > k){
                
                if(--freqMap[nums[start]] == 0){
                    distIntegers--;
                }
                start++;
                
            }
            
            //answer compute
            countSubarrays+=end-start+1;
            
        }
            
        return countSubarrays;
        
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return subWithAtMostXDistinct(nums,k) - subWithAtMostXDistinct(nums,k-1);
        
    }
};