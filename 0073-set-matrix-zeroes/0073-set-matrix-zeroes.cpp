class Solution {
public:

    void setAdjacentRowsAndCols(int i,int j,int rows,int cols,vector<vector<int>>& matrix){

        //setting vertically cells
        for(int r=0;r<rows;r++){
            matrix[r][j]=0;
        }

        //setting horizontally cells
        for(int c=0;c<cols;c++){
            matrix[i][c]=0;
        }

    }

    void setZeroes(vector<vector<int>>& matrix) {
        
        int rows=matrix.size();
        int cols=matrix[0].size();

        vector<pair<int,int>> coordinates;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j] == 0){
                    coordinates.push_back({i,j});
                }
            }
        }
        for(auto [i,j]:coordinates){
            setAdjacentRowsAndCols(i,j,rows,cols,matrix);
        }
    }
};