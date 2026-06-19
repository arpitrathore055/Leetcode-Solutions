class Solution {
public:
    
    void backtrack(int startInd,int& n,int target,vector<int>& currCombination,vector<vector<int>>& sumCombinations,vector<int>& candidates){
        
        //basecase
        if(target == 0){
            sumCombinations.push_back(currCombination);
            return;
        }
        
        //choices
        for(int choice=startInd;choice<n;choice++){
            
            //pruning
            if((target - candidates[choice]) < 0){
                continue;
            }
            
            if(choice > startInd && candidates[choice] == candidates[choice-1]){
                continue;
            }
            
            currCombination.push_back(candidates[choice]);
            
            backtrack(choice+1,n,target - candidates[choice],currCombination,sumCombinations,candidates);
            
            currCombination.pop_back();
            
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> sumCombinations;
        vector<int> currCombination;
        
        int n=candidates.size();
        int startInd=0;
        sort(candidates.begin(),candidates.end());
        backtrack(startInd,n,target,currCombination,sumCombinations,candidates);
        return sumCombinations;
        
    }
};