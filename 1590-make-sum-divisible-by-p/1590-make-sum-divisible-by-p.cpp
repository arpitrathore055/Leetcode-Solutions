class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        long long totalSum=0;
        for(auto num:nums){
            totalSum+=num;
        }
        int extra=totalSum % p;
        
        if(extra == 0){
            return 0;
        }

        unordered_map<int,int> prefix;
        prefix[0]=-1;

        int minLen=nums.size();
        long long prefixSum=0;

        for(int j=0;j<nums.size();j++){

            prefixSum+=nums[j];

            int currprefixSum=(prefixSum % p);

            int requiredPrefixSum=(currprefixSum-extra+p)%p;
            if(prefix.find(requiredPrefixSum) != prefix.end()){
                minLen=min(minLen,(j-prefix[requiredPrefixSum]));
            }
            prefix[currprefixSum]=j;
        }

        return (minLen == nums.size())?-1:minLen;

    }
};