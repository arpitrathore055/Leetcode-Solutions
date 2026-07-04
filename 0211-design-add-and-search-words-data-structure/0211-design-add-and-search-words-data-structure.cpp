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

class WordDictionary {

    TrieNode* root;

public:
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        
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
    
    bool findWord(TrieNode* currNode,int index,int n,string word){
        
        //basecase
        if(index == n){
            return currNode->isWord;
        }
        
        
        if(word[index] == '.'){
            bool isPresent=false;
            for(int i=0;i<26;i++){
                if(currNode->children[i] == nullptr){
                    continue;
                }    
                isPresent = isPresent || findWord(currNode->children[i],index+1,n,word);
            }
            return isPresent;
            
        }else{
            
            if(currNode->children[word[index] - 'a'] == nullptr){
                return false;
            }
            
            return findWord(currNode->children[word[index] - 'a'],index+1,n,word);
            
        }
        
    }
    
    bool search(string word) {
        
        return findWord(root,0,word.length(),word);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */