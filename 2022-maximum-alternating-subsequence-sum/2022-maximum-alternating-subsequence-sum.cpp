class Solution {
public:

    long long dp[1000001][2];
    typedef long long ll;
    ll solve(vector<int>& nums,int ind,bool flag){
        if(ind >= nums.size()){
            return 0;
        }

        if(dp[ind][flag] != -1){
            return dp[ind][flag];
        }

        ll value=nums[ind];
        if(flag == false){
            value-=2*value;
        }
        ll included=solve(nums,ind+1,!flag)+value;
        
        ll excluded=solve(nums,ind+1,flag);
        
        return dp[ind][flag]=max(included,excluded);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,true);
    }
};