class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
  
        vector<int> uniqueDuplicatesPresent;
       
        int n=nums.size();
        for(int i=0;i<n;i++){
            
            while(nums[nums[i]-1] != nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }
            
        }

        for(int i=0;i<n;i++){
            if(nums[i] != i+1){
                uniqueDuplicatesPresent.push_back(nums[i]);
            }
        }
        
        return uniqueDuplicatesPresent;
        
        
    }
};