class Solution {
public:

    int dp[1001][1001];

    int solve(string &text1,string &text2,int ind1,int ind2,int l1,int l2){
        if(ind1 >= l1 || ind2 >= l2){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        if(text1[ind1] == text2[ind2]){
            return dp[ind1][ind2]=1 + solve(text1,text2,ind1+1,ind2+1,l1,l2);
        }
        else{
            return dp[ind1][ind2]=max(solve(text1,text2,ind1+1,ind2,l1,l2),solve(text1,text2,ind1,ind2+1,l1,l2));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.length(),l2=text2.length();
        if(l1==0 || l2==0){
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        return solve(text1,text2,0,0,l1,l2);
    }
};