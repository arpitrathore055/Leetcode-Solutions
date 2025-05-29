class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
        int maxLen=INT_MIN,start=0;
        for(int len=1;len<=n;len++){
            for(int i=0;(i+len-1)<n;i++){
                int j=i+len-1;
                if(i == j){
                    dp[i][j]=true;
                }
                else if(j == i+1){
                    dp[i][j]=(s[i] == s[j]);
                }
                else{
                    dp[i][j]=(s[i] == s[j] && dp[i+1][j-1]);
                }
                if(dp[i][j]){
                    if(maxLen < len){
                        maxLen=len;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};