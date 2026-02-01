class Solution {
public:

    int backtrack(vector<vector<int>>& grid,int i,int j,int& row,int& col){

        //pruning case
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j]==0){
            return 0;
        }

        //apply
        int temp=grid[i][j];
        grid[i][j]=0;

        //recursion
        int left=backtrack(grid,i+1,j,row,col);
        int right=backtrack(grid,i-1,j,row,col);
        int up=backtrack(grid,i,j-1,row,col);
        int down=backtrack(grid,i,j+1,row,col);

        //undo
        grid[i][j]=temp;
        return grid[i][j]+max(left,max(right,max(up,down)));

    }

    int getMaximumGold(vector<vector<int>>& grid) {
        
        int maxGold=0,row=grid.size(),col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int gold=backtrack(grid,i,j,row,col);
                maxGold=max(maxGold,gold);
            }
        }
        return maxGold;

    }
};