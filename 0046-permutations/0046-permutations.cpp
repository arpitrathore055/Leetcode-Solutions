class Solution {
public:
    
    void backtrack(int n,vector<int>& currPermutation,vector<vector<int>>& permutationCollections,vector<bool>& used,vector<int>& nums){
        
        //basecase
        if(currPermutation.size() == n){
            permutationCollections.push_back(currPermutation);
            return;
        }
        
        //choices
        for(int choice=0;choice<n;choice++){
            
            //prunning
            if(used[choice]){
                continue;
            }
            
            //apply and undo
            currPermutation.push_back(nums[choice]);
            used[choice]=true;
            
            backtrack(n,currPermutation,permutationCollections,used,nums);
            
            used[choice]=false;
            currPermutation.pop_back();
            
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> permutationCollections;
        vector<int> currPermutation;
        
        int n=nums.size();
        vector<bool> used(n,false);
        backtrack(n,currPermutation,permutationCollections,used,nums);
        return permutationCollections;
              
    }
};