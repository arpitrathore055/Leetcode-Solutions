class Solution {
public:

    long long dp[13][10001];
    const long long INF=1e18;

    long long solve(int index,int n,int amount_left,vector<int>& coins){
        //prunning
        if(amount_left < 0){
            return INF;
        }

        //basecase
        if(index == n){
            if(amount_left == 0){
                return 0;
            }
            return INF;
        }

        //caching
        if(dp[index][amount_left] != -1){
            return dp[index][amount_left];
        }

        //ans and compute
        long long ans=INF;
        //1.skip
        ans=min(solve(index+1,n,amount_left,coins),ans);
        //2.take same
        ans=min(1 + solve(index,n,amount_left - coins[index],coins),ans);

        //save and return
        return dp[index][amount_left]=ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        memset(dp,-1,sizeof(dp));
        long long minCoinsRequired=solve(0,n,amount,coins);
        return (minCoinsRequired >= INF)?-1:minCoinsRequired;

    }
};