class Solution {
public:

    int m,n;
    int dp[101][101];

    int solve(int i,int j,vector<vector<int>>& grid){
        //base case 
        if(i >= m || j >= n || grid[i][j]==1){
            return 0;
        }

        if(i == (m-1) && j == (n-1)){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int downWays=solve(i+1,j,grid);
        int rightWays=solve(i,j+1,grid);
        return dp[i][j]=downWays + rightWays;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        return solve(0,0,obstacleGrid);
    }
};