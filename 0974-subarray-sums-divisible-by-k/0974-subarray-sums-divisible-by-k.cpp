class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
  
        int n=nums.size();
        unordered_map<int,int> prefix;
        prefix[0]=1;
        
        int currSum=0;
        int countSubarrays=0;
        
        for(int i=0;i<n;i++){
            
            currSum+=nums[i];
            int targetPrefix=((currSum%k)+k)%k;
            if(prefix.find(targetPrefix) != prefix.end()){
                countSubarrays+=prefix[targetPrefix];
            }
            prefix[targetPrefix]++;
            
        }
        
        return countSubarrays;
        
    }
};