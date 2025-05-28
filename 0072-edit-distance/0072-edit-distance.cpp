class Solution {
public:

    int dp[501][501];
    int solve(string word1,string word2,int ind1,int ind2,int m,int n){
        if(ind1 >= m){
            return n-ind2;
        }
        if(ind2 >= n){
            return m-ind1;
        }
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        if(word1[ind1] == word2[ind2]){
            return dp[ind1][ind2]=solve(word1,word2,ind1+1,ind2+1,m,n);
        }
        return dp[ind1][ind2]=min(1+solve(word1,word2,ind1,ind2+1,m,n),min(1+solve(word1,word2,ind1+1,ind2,m,n),1+solve(word1,word2,ind1+1,ind2+1,m,n)));
    }

    int minDistance(string word1, string word2) {

        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,0,0,word1.length(),word2.length());

    }
};