class Solution {
public:

    void backtrack(vector<int>& candidates,int start,int remaining,vector<vector<int>>& result,vector<int>& path){

        if(remaining == 0){
            result.push_back(path);
            return;
        }
        if(remaining < 0){
            return;
        }

        for(int ind=start;ind<candidates.size();ind++){

            //pruning condition
            if(candidates[ind] > remaining){
                continue;
            }

            path.push_back(candidates[ind]);
            backtrack(candidates,ind,remaining-candidates[ind],result,path);
            path.pop_back();

        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> result;
        vector<int> path;
        backtrack(candidates,0,target,result,path);
        return result;
    }
};