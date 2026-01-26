class Solution {
public:

    void backtrack(vector<int>& nums,int start,int n,vector<vector<int>>& result,vector<int>& path){

        //base case
        result.push_back(path);
        
        //exploring choices and pruning
        for(int ind=start;ind<n;ind++){

            //check for pruning
            if(ind > start && nums[ind] == nums[ind-1]){
                continue;
            }
            //apply 
            path.push_back(nums[ind]);
            //recursion
            backtrack(nums,ind+1,n,result,path);
            //undo
            path.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> path;
        int n=nums.size();
        backtrack(nums,0,n,result,path);
        return result;

    }
};