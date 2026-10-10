class Solution {
public:
    
    int countPairs(vector<int>& nums,int k,int middle){
        
        int count=0;
        int start=0;
        
        for(int end=0;end<nums.size();end++){
            
            while((nums[end] - nums[start]) > middle){
                start++;
            }
            
            count+=end-start;
            
        }
        
        return count;
        
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
     
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        int start=0;
        int end=nums[n-1]-nums[0];
        
        int kthSmallestDistance=end;
        
        while(start<=end){
            
            int middle=(end-start)/2 + start;
            
            if(countPairs(nums,k,middle) >= k){
                kthSmallestDistance=min(kthSmallestDistance,middle);
                end=middle-1;
            }
            else{
                start=middle+1;   
            }
            
        }
        
        return kthSmallestDistance;
        
    }
};