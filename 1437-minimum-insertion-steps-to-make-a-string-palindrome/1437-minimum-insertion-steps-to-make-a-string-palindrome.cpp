class Solution {
public:

    int dp[501][501];

    int solve(int i,int j, string& s){
        if(i>=j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == s[j]){
            return dp[i][j]=solve(i+1,j-1,s);
        }
        return dp[i][j]=min(1+solve(i,j-1,s),1+solve(i+1,j,s));
    }

    int minInsertions(string s) {
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,s);
    }
};