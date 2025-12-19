class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int windowSize=0;
        long long int windowSum=0;
        int maxFreq=0;
        int left=0,right=0;

        sort(nums.begin(),nums.end());

        for(;right<nums.size();right++){

            //updation
            windowSum+=nums[right];
            windowSize=(right-left+1);


            //shrinking based on invalid scenerio
            while(((1LL*nums[right]*windowSize)-windowSum) > k){
                windowSum-=nums[left];
                ++left;
                windowSize=(right-left+1);
            }

            //computing ans
            if(((1LL*nums[right]*windowSize)-windowSum) <= k){
                maxFreq=max(maxFreq,windowSize);
            }

        }

        return maxFreq;

    }
};