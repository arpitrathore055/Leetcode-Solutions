class Solution {
public:
    
    bool isSplitPossible(vector<int>& nums,int k,int perSubarraySum){
        
        int countValidSubarrays=0;
        int currSubarraySum=0;
        for(auto& element:nums){
            
            if(currSubarraySum + element <= perSubarraySum){
                currSubarraySum+=element;   
            }else{
                countValidSubarrays++;
                currSubarraySum=element;
            }
            
        }
        if(currSubarraySum <= perSubarraySum){
            countValidSubarrays++;
        }
        
        return countValidSubarrays <= k;
        
    }
    
    int splitArray(vector<int>& nums, int k) {
  
        int n=nums.size();
        int start=*max_element(nums.begin(),nums.end());
        int end=accumulate(nums.begin(),nums.end(),0);
        
        int minimizedLargestSum=end;
        
        while(start<=end){
            
            int middle=(end-start)/2 + start;
            
            if(isSplitPossible(nums,k,middle)){
                minimizedLargestSum=min(minimizedLargestSum,middle);
                end=middle-1;
            }
            else{
                start=middle+1;
            }
            
        }
        
        return minimizedLargestSum;
        
    }
};