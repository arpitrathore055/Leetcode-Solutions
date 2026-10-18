class Solution {
public:
    bool isSafeToMove(vector<vector<int>>& grid, int i, int j, int rows,
                      int cols) {

        if (i >= 0 && j >= 0 && i < rows && j < cols && grid[i][j] != -1) {
            return true;
        }

        return false;
    }

    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void backtrack(vector<vector<int>>& grid, int i, int j, int rows, int cols,
                   int& uniquePathCount,int& remainingCount) {

        // basecase
        if (grid[i][j] == 2) {
            if(remainingCount == 1){
                uniquePathCount++;
            }
            return;
        }

        int gridPrevValue = grid[i][j];
        grid[i][j] = -1;
        remainingCount--;

        for (auto& [x, y] : directions) {

            int newx = i + x;
            int newy = j + y;
            // prunning
            if (!isSafeToMove(grid, newx, newy, rows, cols)) {
                continue;
            }

            // int gridPrevValue=grid[i][j];
            // grid[i][j]=-1;

            backtrack(grid, newx, newy, rows, cols, uniquePathCount,remainingCount);

            // grid[i][j]=-1;
        }

        remainingCount++;
        grid[i][j] = gridPrevValue;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        int uniquePathCount = 0;
        int remainingCount=0;
        int rows = grid.size();
        int cols = grid[0].size();

        int startx=0,starty=0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != -1) {
                    if(grid[i][j] == 1){
                        startx=i;
                        starty=j;
                    }
                    remainingCount++;
                }
            }
        }

        backtrack(grid, startx, starty, rows, cols, uniquePathCount,remainingCount);

        return uniquePathCount;
    }
};