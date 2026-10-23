class Solution {
public:
    
    void bfsTraversal(TreeNode* root,int& maxWidth){
        
        if(root == nullptr){
            return;
        }
        
        queue<pair<TreeNode*,unsigned long long>> qu;
        qu.push({root,0});
        
        while(!qu.empty()){
            
            int size=qu.size();
            unsigned long long frontNodePos=qu.front().second;
            unsigned long long endNodePos=qu.back().second;
            
            for(int i=0;i<size;i++){
                
                pair<TreeNode*,unsigned long long> frontPair=qu.front();
                qu.pop();
                
                if(frontPair.first->left != nullptr){
                    qu.push({frontPair.first->left,(2*frontPair.second)+1});
                }
                
                if(frontPair.first->right != nullptr){
                    qu.push({frontPair.first->right,(2*frontPair.second)+2});
                }
                
            }
            
            maxWidth=max(maxWidth,static_cast<int>(endNodePos-frontNodePos+1));
            
        }
        
    }
    
    int widthOfBinaryTree(TreeNode* root) {
  
        int maxWidth=0;
        bfsTraversal(root,maxWidth);
        return maxWidth;       
        
    }
};