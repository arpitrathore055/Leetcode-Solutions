class Solution {
public:

    void backtrack(vector<int>& nums,vector<bool>& used,vector<int>& path,vector<vector<int>>& result){

        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }

        for(int ind=0;ind<nums.size();ind++){

            //pruning condition
            if(used[ind]){
                continue;
            }
            
            //apply
            path.push_back(nums[ind]);
            used[ind]=true;

            //recursion
            backtrack(nums,used,path,result);

            //undo
            path.pop_back();
            used[ind]=false;

        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(),false);
        backtrack(nums,used,path,result);
        return result;

    }
};