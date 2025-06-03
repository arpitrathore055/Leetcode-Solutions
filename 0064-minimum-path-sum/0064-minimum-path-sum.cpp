class Solution {
public:
    int m,n,dp[201][201];

    int solve(int i,int j,vector<vector<int>>& grid){
        //base case
        if(i >= m || j >= n){
            return INT_MAX;
        }
        if(i == (m-1) && j == (n-1)){
            return grid[m-1][n-1];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j]=grid[i][j]+min(solve(i+1,j,grid),solve(i,j+1,grid));
    }

    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,grid);
    }
};