class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        unordered_map<int,int> prefix;
        prefix[0]=1;

        int count=0;
        int prefixSum=0;

        for(int j=0;j<nums.size();j++){

            prefixSum+=nums[j];

            int requiredPrefixSum=prefixSum-goal;
            if(prefix.find(requiredPrefixSum) != prefix.end()){
                count+=prefix[requiredPrefixSum];
            }

            prefix[prefixSum]++;

        }
        return count;

    }
};