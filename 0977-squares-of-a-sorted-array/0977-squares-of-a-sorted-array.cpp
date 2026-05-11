class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int>finalSortedArray(nums.size(),0);
        int ind=nums.size()-1;
        int left=0,right=nums.size()-1;
        while(left<=right){
            int squaredLeft=nums[left]*nums[left];
            int squaredRight=nums[right]*nums[right];
            if(squaredLeft > squaredRight){
                finalSortedArray[ind]=squaredLeft;
                left++;
            }
            else{
                finalSortedArray[ind]=squaredRight;
                right--;
            }
            ind--;
        }

        return finalSortedArray;
    }
};