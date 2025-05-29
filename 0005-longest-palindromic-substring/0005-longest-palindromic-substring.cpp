class Solution {
public:

    int dp[1001][1001];

    bool check(int i,int j,string& s){
        if(i >= j){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == s[j]){
            return dp[i][j]=check(i+1,j-1,s);
        }
        return dp[i][j]=0;
    }

    string longestPalindrome(string s) {
        int maxLen=INT_MIN,start=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<s.length();i++){
            for(int j=0;j<s.length();j++){
                if(check(i,j,s)){
                    if(maxLen < (j-i+1)){
                        maxLen=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};