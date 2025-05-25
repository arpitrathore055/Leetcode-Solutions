class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int> dp(1001,1);
        sort(pairs.begin(),pairs.end());
        int maxValue=1;
        for(int i=0;i<pairs.size();i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0] > pairs[j][1]){
                    dp[i]=max(dp[j]+1,dp[i]);
                    maxValue=max(maxValue,dp[i]);
                }
            }
        }
        return maxValue;
    }
};