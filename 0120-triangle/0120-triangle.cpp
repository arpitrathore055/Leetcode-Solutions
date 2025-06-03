class Solution {
public:

    int m,n,dp[201][201];

    int solve(int i,int j,vector<vector<int>>& triangle){
        //base case
        if(i >= m || j>= triangle[i].size()){
            return INT_MAX;
        }
        if(i == (m-1)){
            return triangle[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j]=triangle[i][j]+min(solve(i+1,j,triangle),solve(i+1,j+1,triangle));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        m=triangle.size();
        n=triangle[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,triangle);
    }
};