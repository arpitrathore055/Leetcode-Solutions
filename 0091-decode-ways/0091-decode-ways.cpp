class Solution {
public:

    int decodeWays(string& s,int i,int& n,vector<int>& dp){

        if(i==n){
            return 1;
        }

        if(s[i] == '0'){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }
        //taking 1 number only making sure it shouldn;t be 0
        int waysAsSingleNumber=0,waysAsCombinedNumber=0;
        waysAsSingleNumber=decodeWays(s,i+1,n,dp);

        //taking 2 number only making sure it shouldn;t be 0
        if(i+1 < n){
            int combinedNumber=(s[i] - '0')*10+s[i+1] - '0';
            if(combinedNumber > 9 && combinedNumber <27){
                waysAsCombinedNumber=decodeWays(s,i+2,n,dp);
            }
        }

        return dp[i]=waysAsSingleNumber + waysAsCombinedNumber;

    }

    int numDecodings(string s) {

        int n=s.length();
        vector<int> dp(n,-1);
        return decodeWays(s,0,n,dp);
        
    }
};