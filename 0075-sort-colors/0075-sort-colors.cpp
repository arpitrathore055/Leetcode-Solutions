class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            switch(nums[mid]){
                case 0:{
                    int temp=nums[mid];
                    nums[mid]=nums[low];
                    nums[low]=temp;
                    low++;
                    mid++;
                }
                break;
                case 1:{
                    ++mid;
                }
                break;
                case 2:{
                    int temp=nums[mid];
                    nums[mid]=nums[high];
                    nums[high]=temp;
                    --high;
                }
            }
        }
    }
};