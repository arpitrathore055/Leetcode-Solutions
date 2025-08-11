class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zcount=0,i=0,j=0,maxlen=0;
        while(j< nums.size()){
           if(nums[j] ==0 ){
            zcount++;
           }
           if(zcount > k){
            maxlen=max(maxlen,(j-i));
            while(zcount>k){
                if(nums[i] ==0 ){
                    zcount--;
                }
                ++i;
            }
           }
           ++j;
        }
        maxlen=max(maxlen,(j-i));
        return maxlen;
    }
};