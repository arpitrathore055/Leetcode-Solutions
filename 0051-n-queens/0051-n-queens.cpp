class Solution {
public:
    
    bool isSafePlacement(int currRow, int rows,
              int choice, int cols,
              vector<vector<bool>>& queenPlaced) {

    // same column
    for(int r = 0; r < currRow; r++)
        if(queenPlaced[r][choice])
            return false;

    // upper-left diagonal
    for(int r = currRow - 1, c = choice - 1;
        r >= 0 && c >= 0;
        r--, c--)
        if(queenPlaced[r][c])
            return false;

    // upper-right diagonal
    for(int r = currRow - 1, c = choice + 1;
        r >= 0 && c < cols;
        r--, c++)
        if(queenPlaced[r][c])
            return false;

    return true;
}
    
    void backtrack(int currRow,int rows,int cols,vector<string>& currPlacement,vector<vector<string>>& solutions,vector<vector<bool>>& queenPlaced){
        
        //basecase
        if(currRow == rows){
            solutions.push_back(currPlacement);
            return;
        }
        
        for(int choice=0;choice<cols;choice++){
            
            //prunning
            if(!isSafePlacement(currRow,rows,choice,cols,queenPlaced)){
                continue;
            }
            
            //apply and undo
            string placement(cols,'.');
            placement[choice]='Q';
            queenPlaced[currRow][choice]=true;
            
            int oldSize=currPlacement.size();
            currPlacement.push_back(placement);
            
            backtrack(currRow+1,rows,cols,currPlacement,solutions,queenPlaced);
            
            queenPlaced[currRow][choice]=false;
            currPlacement.resize(oldSize);
            
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> solutions;
        vector<string> currPlacement;
        vector<vector<bool>> queenPlaced(n,vector<bool>(n,false));
        
        int rows=n;
        int cols=n;
        int currRow=0;
        
        backtrack(currRow,rows,cols,currPlacement,solutions,queenPlaced);
        return solutions;
        
    }
};