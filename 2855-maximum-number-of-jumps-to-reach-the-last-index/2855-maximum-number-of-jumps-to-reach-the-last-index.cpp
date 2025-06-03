class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(),-1);
        dp[nums.size()-1]=0;
        for(int i=nums.size()-2;i>=0;i--){
            for(int j=i+1;j<=nums.size()-1;j++){
                if(abs(nums[j]-nums[i])<= target && dp[j]!=-1){
                    dp[i]=max(1+dp[j],dp[i]);
                }
            }
        }
        return dp[0];
    }
};