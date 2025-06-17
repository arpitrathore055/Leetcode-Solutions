class Solution {
public:

    int dp[101][101];

    bool helper(int a,int b,string& s1,string& s2,string& s3,int n1,int n2,int n3){
        //base case
        if(a >= n1 || b >=n2){
            if(a >= n1){
                return s2.substr(b) == s3.substr(a+b);
            }
            return s1.substr(a) == s3.substr(a+b);
        }
        if(dp[a][b] != -1){
            return dp[a][b];
        }
        bool fromFirst=false,fromSecond=false;
        if(a < n1 && (a+b) < n3 && s1[a] == s3[a+b]){
            fromFirst = helper(a+1, b, s1, s2, s3, n1, n2, n3);
        }
        if(b < n2 && (a+b) < n3 && s2[b] == s3[a+b]){
            fromSecond = helper(a, b+1, s1, s2, s3, n1, n2, n3);
        }

        return dp[a][b]=fromFirst || fromSecond;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length(),n2=s2.length(),n3=s3.length();
        if(n3 != (n1+n2)){
            return false;
        }
        memset(dp,-1,sizeof(dp));
        return helper(0,0,s1,s2,s3,n1,n2,n3);
    }
};