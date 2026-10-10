class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int start=0;
        int end=nums.size()-1;
        
        while(start<=end){
            
            int middle=((end -start)/2) + start;
            
            if(nums[middle] == target){
                return middle;
            }
            else if(nums[start] <= nums[middle]){
                if(nums[start]<=target && nums[middle]>target){
                    end=middle-1;
                }
                else{
                    start=middle+1;
                }
            }
            else{
                if(nums[middle]<target && nums[end]>=target){
                    start=middle+1;
                }
                else{
                    end=middle-1;
                }
            }
            
        }
        
        return -1;
        
    }
};