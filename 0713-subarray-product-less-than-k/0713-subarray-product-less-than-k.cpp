class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int currProd=1,count=0;
        for(int i=0;i<nums.size();i++){
            int j=i;
            currProd=1;
            for(;j<nums.size();j++){
                currProd*=nums[j];
                if(currProd < k){
                    count++;
                    continue;
                }
                else{
                    break;
                }
            }
            if(j<nums.size()){
                currProd/=nums[i];
            }
        }
        return count;
    }
};