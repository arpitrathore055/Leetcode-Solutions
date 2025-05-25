class Solution {
public:

    int dp[2501][2501];

    int solve(vector<int>& nums,int ind,int prevind){
        if(ind >= nums.size()){
            return 0;
        }
        int take=0;
        if(prevind!=-1 && dp[ind][prevind] != -1){
            return dp[ind][prevind];
        }
        if(prevind == -1 || nums[prevind] < nums[ind]){
            take=1+solve(nums,ind+1,ind);
        }
        int skip=solve(nums,ind+1,prevind);
        if(prevind != -1){
            return dp[ind][prevind]=max(take,skip);    
        }
        return max(take,skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,-1);

    }
};