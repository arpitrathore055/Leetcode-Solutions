class Solution {
public:
    
    bool isSafePlacement(char choice,int x,int y,vector<vector<char>>& board){
        
        int rows=board.size();
        int cols=board[0].size();
        
        //check vertically
        for(int i=0;i<rows;i++){
           if(board[i][y] == choice){
            return false;
           } 
        }
        
        //check horizontally
        for(int j=0;j<cols;j++){
           if(board[x][j] == choice){
            return false;
           } 
        }
        
        //check grid
        for(int i=((x/3)*3);i<(((x/3)*3)+3);i++){
            for(int j=((y/3)*3);j<(((y/3)*3)+3);j++){
    
                if(board[i][j] == choice){
                    return false;
                }
    
            }
        }
        return true;
    }
    
    bool backtrack(vector<vector<char>>& board){
        
        for(int i=0;i<board.size();i++){
            
            for(int j=0;j<board[0].size();j++){
                
                if(board[i][j] == '.'){
                    
                    //choices
                    for(char choice='1';choice<='9';choice++){
                        
                        //prunning
                        if(!isSafePlacement(choice,i,j,board)){
                            continue;
                        }
                        
                        board[i][j]=choice;
                        
                        bool gotAns=backtrack(board);
                        if(gotAns){
                            return true;
                        }
                        
                        board[i][j]='.';
                        
                    }
                    return false;
                }
                
            }
            
        }
        
        return true;
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
  
        backtrack(board);
        
    }
};