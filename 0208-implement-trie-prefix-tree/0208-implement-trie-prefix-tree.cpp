class TrieNode{
  
  public:
    unordered_map<char,TrieNode*> children;
    bool isWord;
    
    TrieNode(){
        isWord=false;    
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
            
            if(!currNode->children.count(ch)){
                currNode->children[ch]=new TrieNode();
            }
            currNode=currNode->children[ch];
        }
        currNode->isWord=true;
        
    }
    
    bool search(string word) {
        
        TrieNode* currNode=root;
        for(auto ch:word){
            
            if(!currNode->children.count(ch)){
                return false;
            }
            currNode=currNode->children[ch];
        }
        return currNode->isWord;
        
    }
    
    bool startsWith(string prefix) {
        
        TrieNode* currNode=root;
        for(auto ch:prefix){
            
            if(!currNode->children.count(ch)){
                return false;
            }
            currNode=currNode->children[ch];
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