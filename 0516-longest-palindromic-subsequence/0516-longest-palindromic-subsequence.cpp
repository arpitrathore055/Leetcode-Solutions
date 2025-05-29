class Solution {
public:

    int dp[1001][1001];

    int solve(string& a,string& b,int i1,int i2,int m,int n){
        if(i1 >= m || i2 >= n){
            return 0;
        }
        if(dp[i1][i2] != -1){
            return dp[i1][i2];
        }
        if(a[i1] == b[i2]){
            return dp[i1][i2]=1 + solve(a,b,i1+1,i2+1,m,n);
        }
        return dp[i1][i2]=max(solve(a,b,i1+1,i2,m,n),solve(a,b,i1,i2+1,m,n));
    }

    int longestPalindromeSubseq(string s) {
        string sc=string(s.rbegin(),s.rend());
        memset(dp,-1,sizeof(dp));
        return solve(s,sc,0,0,s.length(),s.length());
    }
};