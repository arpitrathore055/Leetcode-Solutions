class Solution {
public:

    int dp[1001][1001];

    int check(int i,int j,string s){
        if(i > j){
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == s[j]){
            return dp[i][j]=check(i+1,j-1,s);
        }
        return false;
    }

    int countSubstrings(string s) {
        int len=s.length(),count=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<len;i++){
            for(int j=i;j<len;j++){
                if(check(i,j,s)){
                    ++count;
                }
            }
        }
        return count;
    }
};