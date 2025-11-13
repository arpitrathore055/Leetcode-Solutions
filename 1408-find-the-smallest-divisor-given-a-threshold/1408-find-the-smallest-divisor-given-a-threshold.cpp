class Solution {
public:

    bool checkValidDivisor(vector<int>& nums,int& middle,int& threshold){

        int currDivisorSum=0;
        for(int num:nums){
            currDivisorSum+=((num%middle) == 0)?(num/middle):(num/middle)+1;
            if(currDivisorSum > threshold){
                return false;
            }
        }
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        
        auto result=max_element(nums.begin(),nums.end());
        int start=1;
        int end=*result;

        int minDivisor=end;
        while(start<=end){

            int middle=start+(end-start)/2;
            bool isValidDivisor=checkValidDivisor(nums,middle,threshold);

            if(!isValidDivisor){
                start=middle+1;
            }
            else{
                minDivisor=min(minDivisor,middle);
                end=middle-1;
            }

        }

        return minDivisor;
    }
};