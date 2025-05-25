class Solution {
public:

    int dp[1001][1001];
    int solve(vector<vector<int>>& pairs,int ind,int prevind){
        if(ind >= pairs.size()){
            return 0;
        }
        if(prevind !=-1 && dp[ind][prevind] != -1){
            return dp[ind][prevind];
        }
        int prevValue=0;
        if(prevind != -1){
            prevValue=pairs[prevind][1];
        }
        int currValue=pairs[ind][0],take=0;
        if(prevind == -1 || prevValue < currValue){
            take=1+solve(pairs,ind+1,ind);
        }
        int skip=solve(pairs,ind+1,prevind);
        if(prevind != -1){
            return dp[ind][prevind]=max(take,skip);
        }
        return max(take,skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp,-1,sizeof(dp));
        sort(pairs.begin(),pairs.end());
        return solve(pairs,0,-1);
    }
};