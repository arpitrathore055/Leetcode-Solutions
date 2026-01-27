class Solution {
public:

     bool canPlaceQueenHere(int& n,int row,int col,vector<vector<string>>& board){

        //horizonatal check
        for(int i=0;i<n;i++){
            if(board[row][i] == "Q"){
                return false;
            }
        }

        //vertical check
        for(int i=0;i<n;i++){
            if(board[i][col] == "Q"){
                return false;
            }
        }
        
        //right diagonal
        int currRow=row,currCol=col;
        while(row<n && col<n){
            if(board[row][col]=="Q"){
                return false;
            }
            row++;
            col++;
        }
        //left diagonal
        row=currRow,col=currCol;
        while(row>=0 && col>=0){
            if(board[row][col]=="Q"){
                return false;
            }
            row--;
            col--;
        }
        row=currRow,col=currCol;
        while(row<n && col>=0){
            if(board[row][col]=="Q"){
                return false;
            }
            row++;
            col--;
        }
        //left diagonal
        row=currRow,col=currCol;
        while(row>=0 && col<n){
            if(board[row][col]=="Q"){
                return false;
            }
            row--;
            col++;
        }
        return true;
        
    }

    void backtrack(vector<vector<string>>& board,int row,int& n,int& count){

        //base case
        if(row == n){
            count++;
            return;
        }

        //choices
        for(int i=0;i<n;i++){

            //pruning case
            if(!canPlaceQueenHere(n,row,i,board)){
                continue;
            }

            //apply
            board[row][i]="Q";

            //recursion
            backtrack(board,row+1,n,count);

            //undo
            board[row][i]=".";

        }

    }

    int totalNQueens(int n) {

        vector<vector<string>> board(n,vector<string>(n,"."));
        int count=0;
        backtrack(board,0,n,count);
        return count;
        
    }
};