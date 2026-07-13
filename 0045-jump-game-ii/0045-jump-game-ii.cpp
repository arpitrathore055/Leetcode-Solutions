#include<bits/stdc++.h>

class Solution {
public:

    int dp[10001];

    int solve(int index,int n,vector<int>& nums){

        //prunning
        if(index >= n){
            return INT_MAX;
        }

        //basecase
        if(index == n-1){
            return 0;
        }

        //caching
        if(dp[index] != -1){
            return dp[index];
        }

        //ans compute
        int minJumps=INT_MAX;
        for(int i=1;i<=nums[index];i++){
            int ans=solve(index + i,n,nums);
            if(ans != INT_MAX){
                minJumps=min(minJumps,ans + 1);
            }
        }

        //save and return
        return dp[index]=minJumps;
    
    }

    int jump(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        return solve(0,nums.size(),nums);

    }
};
