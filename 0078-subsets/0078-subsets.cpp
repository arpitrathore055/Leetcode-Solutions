class Solution {
public:

    void backtrack(vector<int>& nums,int ind,int& n,vector<vector<int>>& subs,vector<int>& path){

        //base condition
        if(ind == n){
            subs.push_back(path);
            return;
        }

        //choices
        //apply part
        path.push_back(nums[ind]);
        //recursion part for inclusion
        backtrack(nums,ind+1,n,subs,path);
        //undo part
        path.pop_back();

        //recursion part for exclusion
        backtrack(nums,ind+1,n,subs,path);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>subs;
        vector<int>path;
        int n=nums.size();
        backtrack(nums,0,n,subs,path);
        return subs;
    }
};