class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int start=sqrt(i)+1;
            for(;start>=1;start--){
                int square=start*start;
                if(square <= i){
                    int divisor=(i/square),remNum=(i-(square*divisor));
                    dp[i]=min(dp[i],dp[remNum]+divisor);
                }
            }
        }
        return dp[n];
    }
};