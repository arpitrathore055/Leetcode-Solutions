class Solution {
public:
    
    bool isValidPlacement(int row,int col,int n,vector<vector<bool>>& queenPlaced){
        
        bool isSafeToPlace=true;
        //vertical check
        for(int i=row;i>=0;i--){
            if(queenPlaced[i][col]){
                return false;
            }
        }
        
        //horizontal check
        for(int i=col;i>=0;i--){
            if(queenPlaced[row][i]){
                return false;
            }
        }
        
        //upper right diagonal
        for(int i=row,j=col;i>=0 && j < n;i--,j++){
            if(queenPlaced[i][j]){
                return false;
            }
        }
        
        //upper left diagonal
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(queenPlaced[i][j]){
                return false;
            }
        }
        
        return isSafeToPlace;
        
    }
    
    void backtrack(vector<string>& validPlacement,int row,int n,vector<vector<string>>& validCombinations,vector<vector<bool>>& queenPlaced){
        
        if(row == n){
            //validPlacement : [".......Q...."]["..Q........."][".........Q."]["....Q......"]
            validCombinations.push_back(validPlacement);
            return;
        }
        
        for(int col=0;col<n;col++){
            
            if(!isValidPlacement(row,col,n,queenPlaced)){
                continue;
            }
            
            string currentRowPlacement(n,'.');
            currentRowPlacement[col]='Q';
            
            int prevSizeValidPlacement=validPlacement.size();
            validPlacement.push_back(currentRowPlacement);
            queenPlaced[row][col]=true;
            
            backtrack(validPlacement,row+1,n,validCombinations,queenPlaced);
            
            queenPlaced[row][col]=false;
            validPlacement.resize(prevSizeValidPlacement);
            
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> validCombinations;
        vector<string> validPlacement;
        vector<vector<bool>> queenPlaced(n,vector<bool>(n,false));
        
        backtrack(validPlacement,0,n,validCombinations,queenPlaced);
        
        return validCombinations;
        
    }
    
};