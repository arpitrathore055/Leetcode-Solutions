class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
        dp[0][0]=(obstacleGrid[0][0] == 1)?0:1;
        for(int i=1;i<obstacleGrid.size();i++){
            if(obstacleGrid[i][0]!=1 && obstacleGrid[i-1][0]!=1){
                dp[i][0]=1;
            }
            else{
                break;
            }
        }
        for(int j=1;j<obstacleGrid[0].size();j++){
            if(obstacleGrid[0][j]!=1 && obstacleGrid[0][j-1]!=1){
                dp[0][j]=1;
            }
            else{
                break;
            }
        }
        for(int i=1;i<obstacleGrid.size();i++){
            for(int j=1;j<obstacleGrid[0].size();j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }
                else{
                    int upWays=dp[i-1][j];
                    int leftWays=dp[i][j-1];
                    dp[i][j]=upWays+leftWays;
                }
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};