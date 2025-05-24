class Solution {
public:

    long long dp[1000001][2];

    long long maxAlternatingSum(vector<int>& nums) {
        
        for(int i=1;i<=nums.size();i++){
            dp[i][0]=max(dp[i-1][1]-nums[i-1],dp[i-1][0]);
            dp[i][1]=max(dp[i-1][0]+nums[i-1],dp[i-1][1]);
        }
        return max(dp[nums.size()][0],dp[nums.size()][1]);

    }
};