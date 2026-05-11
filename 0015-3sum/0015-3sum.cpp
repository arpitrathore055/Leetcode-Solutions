class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>finalTriplets;
        set<vector<int>> unst;
        int n=nums.size();
        if(n < 3){
            return finalTriplets; 
        }
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-2;i++){

            int left=i+1,right=nums.size()-1;
            while(left<right){
                if((nums[i] + nums[left] + nums[right]) == 0){
                    if(unst.find({nums[i],nums[left],nums[right]}) == unst.end()){
                        finalTriplets.push_back({nums[i],nums[left],nums[right]});
                        unst.insert({nums[i],nums[left],nums[right]});
                    }
                    left++;right--;
                }
                else if((nums[i] + nums[left] + nums[right]) > 0){
                    right--;
                }
                else{
                    left++;
                }
            }

        }

        return finalTriplets;
    }
};