class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int l=0,r=0,n=nums.size();
        int countSubarrays=0,product=1;
        for(;r<n;r++){

            //upadation part
            product*=nums[r];

            //invalid scenerio
            while(product >= k && l<=r){
                product/=nums[l];
                l++;
            }

            //ans computation
            countSubarrays+=(r-l+1);

        }

        return countSubarrays;
    }
};