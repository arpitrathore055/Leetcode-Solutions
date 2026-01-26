class Solution {
public:

    void backtrack(vector<int>& nums,vector<int>& path,vector<bool>& used,vector<vector<int>>& result){

        //base condition
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }

        //exploration part
        for(int ind=0;ind<nums.size();ind++){

            //pruning condition
            if(used[ind]){
                continue;
            }
            if(ind > 0 && nums[ind] == nums[ind-1] && !used[ind-1]){
                continue;
            }

            //apply 
            path.push_back(nums[ind]);
            used[ind]=true;

            //recursion
            backtrack(nums,path,used,result);

            //undo
            path.pop_back();
            used[ind]=false;

        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(),false);
        backtrack(nums,path,used,result);
        return result;

    }
};