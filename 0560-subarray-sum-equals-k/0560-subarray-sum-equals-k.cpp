class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
        unordered_map<int,int> prefix;
        prefix[0]=1;
        int countSubarrays=0;
        int currSum=0;
        
        for(int i=0;i<n;i++){
            
            currSum+=nums[i];
            
            int targetPrefix=currSum - k;
            
            if(prefix.find(targetPrefix) != prefix.end()){
                countSubarrays+=prefix[targetPrefix];
            }
            prefix[currSum]++;
                        
        }
        return countSubarrays;
        
    }
};