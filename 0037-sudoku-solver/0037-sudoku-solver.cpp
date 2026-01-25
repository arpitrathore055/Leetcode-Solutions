class Solution {
public:

    bool canPlaceCh(vector<vector<char>>& board,int i,int j,char ch){

        for(int k=0;k<9;k++){
            if(board[i][k] == ch){
                return false;
            }
            if(board[k][j] == ch){
                return false;
            }
            int br = 3 * (i / 3) + k / 3;
            int bc = 3 * (j / 3) + k % 3;
            if(board[br][bc] == ch){
                return false;
            }
        }
        return true;

    }

    bool backtrack(vector<vector<char>>& board){

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    for(char ch='1';ch<='9';ch++){
                        if(!canPlaceCh(board,i,j,ch)){
                            continue;
                        }
                        board[i][j]=ch;
                        if(backtrack(board)){
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