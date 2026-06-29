class Solution {
public:

    int dp[100001][2][3];

    int solve(int day,int holding,int cap,vector<int>& prices){
        //dp[day][holding][cap]=maximum profit you can achieve from day "day" to N-1, currently holding/not holding a stock and currently have "cap" to take into consideration

        //prunning
        //basecase
        if(day == prices.size()){
            return 0;
        }
        if(cap == 0){
            return 0;
        }

        //caching
        if(dp[day][holding][cap] != -1){
            return dp[day][holding][cap];
        }

        //ans compute
        if(holding){
            //sell,hold
            return dp[day][holding][cap]=max(prices[day] + solve(day+1,0,cap-1,prices),solve(day+1,1,cap,prices));
        }
        else{
            //buy,skip
            return dp[day][holding][cap]=max(-prices[day] + solve(day+1,1,cap,prices),solve(day+1,0,cap,prices));
        }

    }

    int maxProfit(vector<int>& prices) {
        
        memset(dp,-1,sizeof(dp));
        return solve(0,0,2,prices);
    }
};