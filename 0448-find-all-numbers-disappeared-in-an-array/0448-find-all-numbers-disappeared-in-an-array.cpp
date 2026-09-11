class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> missingElements;
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            
            while(nums[nums[i] - 1] != nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }
            
        }
        
        for(int i=0;i<n;i++){
            if(nums[i] != i+1){
                missingElements.push_back(i+1);
            }
        }
        
        return missingElements;
        
    }
};