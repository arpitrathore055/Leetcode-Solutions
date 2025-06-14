class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int totalExpected=(nums.size()*(nums.size()+1))/2,currentTotal=0;
        for(int num:nums){
            currentTotal+=num;
        }
        return (totalExpected - currentTotal);

    }
};