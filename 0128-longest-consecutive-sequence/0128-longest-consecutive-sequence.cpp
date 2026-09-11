class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> numberSet;
        for(auto num:nums){
            numberSet.insert(num);
        }
        
        int maxLCS=0;
        
        for(auto num:numberSet){
        
            if(numberSet.count(num-1) == 0){
                
                int end=num;
                for(;numberSet.count(end) != 0;end++){
                    maxLCS=max(maxLCS,(end - num + 1));
                }     
                 
            }
        
        }
        
        return maxLCS;

    }
};