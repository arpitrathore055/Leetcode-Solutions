class Solution {
public:

    int dp[100001][2][2];

    int solve(int day,int bought,int cap,vector<int>& prices){
        //prunning
        //basecase
        if(day == prices.size()){
            return 0;
        }
        if(cap == 0){
            return 0;
        }

        if(dp[day][bought][cap] != -1){
            return dp[day][bought][cap];
        }

        if(bought == 1){
            //max(sell, hold)
            return dp[day][bought][cap]=max(prices[day] + solve(day+1,0,cap-1,prices),solve(day+1,1,cap,prices));
        }
        else{
            //max(buy,skip)
            return dp[day][bought][cap]=max(solve(day+1,1,cap,prices) - prices[day],solve(day+1,0,cap,prices));
        }

    }

    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,1,prices);

    }
};