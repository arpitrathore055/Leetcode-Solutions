class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int currSum=0;
        int maxSumAchieved=INT_MIN;
        for(auto elements:nums){
            currSum=max(currSum + elements,elements);
            maxSumAchieved=max(maxSumAchieved,currSum);
            if(currSum < 0){
                currSum=0;
            }
            
        }
        return maxSumAchieved;

    }
};