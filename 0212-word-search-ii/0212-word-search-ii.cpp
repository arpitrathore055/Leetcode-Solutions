class TrieNode{
  
  public:
    TrieNode* children[26];
    bool isWord;
    
    TrieNode(){
        isWord=false;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }    
    }
    
};

class Trie{
  
  TrieNode* root;
  
public:
    
    Trie(){
        root=new TrieNode();
    }
    
    void insert(string word){
        
        TrieNode* currNode=root;
        for(auto ch:word){
            int index=ch - 'a';
            if(currNode->children[index] == nullptr){
                currNode->children[index]=new TrieNode();
            }
            currNode=currNode->children[index];
        }
        currNode->isWord=true;
    
    }
    
    TrieNode* getTrieRoot(){
        return root;
    }
    
};


vector<vector<bool>> boardVisited; 

class Solution {
public:
    
    vector<pair<int,int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
    
    void backtrack(int i,int j,int rows,int cols,string& currString,vector<string>& foundWords,vector<vector<char>>& board,TrieNode* currNode){
        
        //basecase
        if(currNode->isWord){
            foundWords.push_back(currString);
            currNode->isWord=false;
        }
        
        boardVisited[i][j]=true;
        
        //choices
        for(auto [xval,yval]:directions){

            int newx=i + xval;
            int newy=j + yval;
            //prunning
            if(newx < 0 || newx >= rows || newy < 0 || newy >=cols || currNode->children[board[newx][newy] - 'a'] == nullptr || boardVisited[newx][newy]){
                continue;
            }
        
            //apply and undo
            currString.push_back(board[newx][newy]);
            
            backtrack(newx,newy,rows,cols,currString,foundWords,board,currNode->children[board[newx][newy] - 'a']);
            
            currString.pop_back();
            
        }
        
        boardVisited[i][j]=false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        vector<string> foundWords;
        string currString="";
        Trie* trieObj=new Trie();
        
        for(auto word:words){
            trieObj->insert(word);
        }
        
        TrieNode* currNode=trieObj->getTrieRoot();
        
        int rows=board.size();
        int cols=board[0].size();
        boardVisited.assign(rows,vector<bool>(cols,false));
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                char ch=board[i][j];
                if(currNode->children[ch - 'a'] != nullptr){
                    currString.push_back(ch);
                    backtrack(i,j,rows,cols,currString,foundWords,board,currNode->children[ch - 'a']);
                    currString.pop_back();
                }
            }
        }
        
        return foundWords;
        
    }
};