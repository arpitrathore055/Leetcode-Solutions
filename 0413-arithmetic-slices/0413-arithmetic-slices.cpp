class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int len=nums.size(),count=0;
        for(int i=0;i<=(len-3);i++){
            int diff=INT_MAX;
            for(int j=i+1;j<len;j++){
                if(diff == INT_MAX){
                    diff=nums[j]-nums[j-1];
                }
                if((nums[j]-nums[j-1]) == diff){
                    int currSubArrayLen=j-i+1;
                    if(currSubArrayLen >= 3){
                        count++;
                    }
                }
                else{
                    break;
                }
            }
        }
        return count;
    }
};