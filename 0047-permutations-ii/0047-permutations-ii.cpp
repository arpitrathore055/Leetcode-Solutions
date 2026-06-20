class Solution {
public:
    
    void backtrack(int n,vector<int>& currPermutation,vector<vector<int>>& uniqueCollection,vector<bool>& used,vector<int>& nums){
        
        //basecase
        if(currPermutation.size() == n){
            uniqueCollection.push_back(currPermutation);
            return;
        }

        //choice
        for(int choice=0;choice<n;choice++){
            
            //prunning
            if(used[choice]){
                continue;
            }
            
            //condition to avoid duplicate
            if(choice > 0 && nums[choice] == nums[choice - 1] && !used[choice - 1]){
                continue;
            }
            
            //apply and undo
            currPermutation.push_back(nums[choice]);
            used[choice]=true;
            
            backtrack(n,currPermutation,uniqueCollection,used,nums);
            
            used[choice]=false;
            currPermutation.pop_back();
            
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> uniqueCollection;
        vector<int> currPermutation;
        
        int n=nums.size();
        vector<bool> used(n,false);
        sort(nums.begin(),nums.end());

        backtrack(n,currPermutation,uniqueCollection,used,nums);
        return uniqueCollection;
        
    }
};