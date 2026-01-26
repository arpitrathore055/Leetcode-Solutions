class Solution {
public:

    bool dfs(vector<vector<char>>& board,int i,int j,int& row,int& col,string& word,int ind){

        //base case
        if(ind == word.size()){
            return true;
        }

        //pruning case
        if(i < 0 || i >= row || j < 0 || j >=col || board[i][j] != word[ind]){
            return false;
        }

        //apply
        char temp=board[i][j];
        board[i][j]='#';

        //recursion
        bool found=dfs(board,i+1,j,row,col,word,ind+1) || dfs(board,i,j+1,row,col,word,ind+1) || dfs(board,i-1,j,row,col,word,ind+1) || dfs(board,i,j-1,row,col,word,ind+1);

        //undo
        board[i][j]=temp;
        return found;

    }

    bool exist(vector<vector<char>>& board, string word) {
    
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j] == word[0]){
                    if(dfs(board,i,j,row,col,word,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};