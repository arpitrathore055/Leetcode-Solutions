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


class Trie {
    
    TrieNode* root;
    
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        
        TrieNode* currNode=root;
        for(auto ch:word){
            int index=ch-'a';
            
            if(currNode->children[index] == nullptr){
                currNode->children[index]=new TrieNode();
            }
            
            currNode=currNode->children[index];
        }
        currNode->isWord=true;
    }
    
    bool search(string word) {
        TrieNode* currNode=root;
        for(auto ch:word){
            int index=ch-'a';
            if(currNode->children[index] == nullptr){
                return false;
            }
            currNode=currNode->children[index];
        }
        return currNode->isWord;
    }
    
    bool startsWith(string prefix) {
     
        TrieNode* currNode=root;
        for(auto ch:prefix){
            int index=ch-'a';
            if(currNode->children[index] == nullptr){
                return false;
            }
            currNode=currNode->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */