class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<long long> prefix(n+1,0);
        
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        
        deque<int> dq;
        int minSubstringLen=n+1;
        
        for(int i=0;i<=n;i++){
            
            long long targetPrefixSum=prefix[i]-k;
            
            while(!dq.empty() && prefix[dq.front()] <= targetPrefixSum){
                minSubstringLen=min(minSubstringLen,i - dq.front());
                dq.pop_front();
            }
            
            while(!dq.empty() && prefix[dq.back()] > prefix[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
            
        }
        
        return (minSubstringLen == n+1)? -1 :minSubstringLen;
        
    }
};