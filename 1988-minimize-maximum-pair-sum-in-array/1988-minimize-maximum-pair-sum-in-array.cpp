class Solution {
public:

    int isPairSumValid(vector<int>& nums,int& middle,int& n){
        
        for(int i=0;i<(n/2);i++){
            if((nums[i]+nums[n-1-i]) > middle){
                return nums[i]+nums[n-1-i];
            }
        }
        return middle;

    }

    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int start=nums[0]+nums[1];
        int end=nums[n-1]+nums[n-2];
        int minAns=end;
        while(start<=end){
            int middle=start+(end-start)/2;
            int currAns=isPairSumValid(nums,middle,n);

            if(currAns > middle){
                start=middle+1;
            }
            else{
                minAns=min(minAns,middle);
                end=middle-1;
            }
        }
        return minAns;
    }
};