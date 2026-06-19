class Solution {
public:
    
    void backtrack(int startInd,int& n,int target,vector<int>& currCombination,vector<vector<int>>& sumCombinations,vector<int>& candidates){
        
        //base case
        if(startInd == n){
            if(target == 0){
                sumCombinations.push_back(currCombination);
            }
            return;
        }
        
        //choices
        //1.take same
        if((target - candidates[startInd]) >=0){
            
            currCombination.push_back(candidates[startInd]);
            backtrack(startInd,n,target - candidates[startInd],currCombination,sumCombinations,candidates);
            currCombination.pop_back();
            
        }
        
        //2.not take and move next
        backtrack(startInd+1,n,target,currCombination,sumCombinations,candidates);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> sumCombinations;
        vector<int> currCombination;
        
        int n=candidates.size();
        int startInd=0;
        backtrack(startInd,n,target,currCombination,sumCombinations,candidates);
        return sumCombinations;
        
    }
};