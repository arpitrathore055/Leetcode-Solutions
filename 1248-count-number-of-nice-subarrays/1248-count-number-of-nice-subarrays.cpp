class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        for(int i=0;i<nums.size();i++){
            if((nums[i] % 2) == 0){
                nums[i]=0;
            }
            else{
                nums[i]=1;
            }
        }

        unordered_map<int,int> prefix;
        prefix[0]=1;

        int count=0;
        int prefixSum=0;

        for(int j=0;j<nums.size();j++){

            prefixSum+=nums[j];
            int requiredPrefixSum=prefixSum-k;
            if(prefix.find(requiredPrefixSum) != prefix.end()){
                count+=prefix[requiredPrefixSum];
            }

            prefix[prefixSum]++;

        }
        return count;

    }
};