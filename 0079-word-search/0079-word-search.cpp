class Solution {
public:
    
    vector<pair<int,int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
    
    bool backtrack(int i,int j,int wordInd,vector<vector<char>>& board,string& word,vector<vector<bool>>& visited,int& rows,int& cols){
        
        //basecase
        if(wordInd == word.size()){
            return true;
        }
        visited[i][j]=true;
        
        //choices
        for(auto [xval,yval]:directions){
            
            //prunning
            int newx=i + xval;
            int newy=j + yval;
            if(newx < 0 || newx >= rows || newy < 0 || newy >= cols || visited[newx][newy] || board[newx][newy] != word[wordInd]){
                continue;
            }
            
            //apply and undo
            bool ans=backtrack(newx,newy,wordInd+1,board,word,visited,rows,cols);
            if(ans){
                return true;
            }
        }
        
        visited[i][j]=false;
        return false;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
       
       bool wordPresent=false;
       int rows=board.size();
       int cols=board[0].size();
       vector<vector<bool>> visited(rows,vector<bool>(cols,false));
       
       int wordInd=0;
       
       for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(!visited[i][j] && board[i][j] == word[wordInd]){
                wordPresent=backtrack(i,j,wordInd+1,board,word,visited,rows,cols);
                if(wordPresent){
                    return true;
                }
            }
        }
       }
       
       return wordPresent;
    }
};