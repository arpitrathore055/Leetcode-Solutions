class Solution {
public:
    int jump(vector<int>& nums) {
  
        int n=nums.size();
        int minJumpsReq=0;
        int fartestBoundary=0;
        int insideBoundary=0;
        
        for(int i=0;i<n-1;i++){
            
            fartestBoundary=max(fartestBoundary,nums[i]+i);
            
            if(i == insideBoundary){
                minJumpsReq++;
                insideBoundary=fartestBoundary;
            }
            
        }
        
        return minJumpsReq;
        
    }
};