class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                nums[i]=-1;
            }
        }
        
        unordered_map<int,int> prefix;
        prefix[0]=-1;
        int maxLen=0,currPrefixSum=0;

        for(int j=0;j<nums.size();j++){

            currPrefixSum+=nums[j];

            int requiredPrefixSum=currPrefixSum;
            if(prefix.find(requiredPrefixSum) != prefix.end()){
                maxLen=max(maxLen,(j-prefix[requiredPrefixSum]));
            }
            else{
                prefix[requiredPrefixSum]=j;
            }

        }

        return maxLen;
    }
};