class Solution {
public:

    int dp[1001][1001];

    int helper(int i,int j,string& s,string& t,int n,int m){
        if(i!=n && j==m || i==n && j==m){
            return 1;
        } 
        if(i==n && j!=m){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int include=0,notIncluded=0;
        if(s[i] == t[j]){
            include=helper(i+1,j+1,s,t,n,m);
        }
        notIncluded=helper(i+1,j,s,t,n,m);
        return dp[i][j]=include+notIncluded;
    }

    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        memset(dp,-1,sizeof(dp));
        return helper(0,0,s,t,n,m);
        
    }
};