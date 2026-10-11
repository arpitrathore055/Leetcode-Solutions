class Solution {
public:
    
    pair<int,int> partition(vector<int>& nums,int start,int end){
        
        int randomIndex=start+rand()%(end-start+1);
        int pivot=nums[randomIndex];
        
        int lt=start,i=start,gt=end;
        
        while(i<=gt){
            
            if(nums[i] == pivot){
                i++;
            }
            else if(nums[i] < pivot){
                swap(nums[lt],nums[i]);
                lt++;
                i++;
            }
            else{
                swap(nums[gt],nums[i]);
                gt--;
            }
            
        }
        
        return {lt,gt};
        
    }
    
    int quickSelectionAlgo(vector<int>& nums,int start,int end,int targetIndex){
        
        //basecase
        if(start == end){
            return nums[start];
        }
        
        pair<int,int> pivot=partition(nums,start,end);
        
        if(targetIndex <pivot.first){
            return quickSelectionAlgo(nums,start,pivot.first-1,targetIndex);
        }
        else if(targetIndex > pivot.second){
            return quickSelectionAlgo(nums,pivot.second+1,end,targetIndex);
        }
        else{
            return nums[targetIndex];
        }
        
    }
    
    int findKthLargest(vector<int>& nums, int k) {
  
        return quickSelectionAlgo(nums,0,nums.size()-1,nums.size()-k);
        
    }
};