class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCount=0,i=0,j=0,maxlen=0;
        while(j < nums.size()){

            if(nums[j] == 0){
                zeroCount++;
            }
            if(zeroCount > 1){
                while(zeroCount >1){
                    maxlen=max(maxlen,(j-i-1));
                    if(nums[i] == 0){
                        zeroCount--;
                    }
                    ++i;
                }
            }
            ++j;
        }
        if(zeroCount == 1 || zeroCount == 0){
            maxlen=max(maxlen,(j-i-1));
        }
        return maxlen;
    }
};