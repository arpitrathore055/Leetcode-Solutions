class Solution {
public:
    
    void backtrack(int startInd,int k,int target,vector<int>& currCombination,vector<vector<int>>& sumCombinations){
        
        //basecase
        if(k < 0){
            return;
        }
        
        if(k == 0){
            if(target == 0){
                sumCombinations.push_back(currCombination);
            }
            return;
        }
        
        for(int choice=startInd;choice<=9;choice++){
            
            //pruning
            if((target - choice) < 0){
                break;
            }
            
            currCombination.push_back(choice);
            
            backtrack(choice+1,k-1,target - choice,currCombination,sumCombinations);
            
            currCombination.pop_back();
            
        }
        
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
     
        vector<vector<int>> sumCombinations;
        vector<int> currCombination;
        
        backtrack(1,k,n,currCombination,sumCombinations);
        return sumCombinations;
        
    }
};