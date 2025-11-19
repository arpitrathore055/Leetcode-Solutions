class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int i=rows-1,j=0;
        int count=0;
        while(i >=0 && j<cols){
            if(grid[i][j] < 0){
                count+= cols-j;
                --i;
            }
            else{
                while(j<cols && grid[i][j] >= 0){
                    ++j;
                }
            }
        }
        return count;
    }
};