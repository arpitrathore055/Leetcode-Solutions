class Solution {
public:

    int dp[30001][2];

    int solve(int day,int holding,vector<int>& prices){
        //prunning
        //basecase
        if(day == prices.size()){
            return 0;
        }

        //caching
        if(dp[day][holding] != -1){
            return dp[day][holding];
        }

        //ans compute
        if(holding == 1){
            //max(sell,hold)
            return dp[day][holding]=max(prices[day] + solve(day+1,0,prices),solve(day+1,1,prices));
        }
        else{
            //max(buy,skip)
            return dp[day][holding]=max(-prices[day] + solve(day+1,1,prices),solve(day+1,0,prices));
        }

    }

    int maxProfit(vector<int>& prices) {
        
        memset(dp,-1,sizeof(dp));
        return solve(0,0,prices);

    }
};