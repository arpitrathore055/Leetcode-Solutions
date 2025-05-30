class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int len=1;len<=n;len++){
            for(int i=0;(i+len-1)<n;i++){
                int j=i+len-1;
                if(i == j){
                    dp[i][j]=0;
                }
                else if(s[i] == s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};