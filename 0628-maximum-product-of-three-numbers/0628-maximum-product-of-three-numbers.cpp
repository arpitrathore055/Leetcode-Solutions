class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        sort(begin(nums),end(nums));
        int n=nums.size();
        return max(max(nums[0]*nums[1]*nums[2],nums[n-1]*nums[n-2]*nums[n-3]),max(nums[0]*nums[1]*nums[n-1],nums[n-1]*nums[n-2]*nums[0]));

    }
};