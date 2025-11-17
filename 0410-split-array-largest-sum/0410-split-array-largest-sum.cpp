class Solution {
public:

    int isSumValueEnough(vector<int>& nums,int& middle,int& m){

        int currSum=0;
        int countSubarrays=1;
        for(int num:nums){
            if(num > middle){
                return num;
            }
            if((currSum+num) <= middle){
                currSum+=num;
            }
            else{
                countSubarrays++;
                currSum=num;
            }
            if(countSubarrays > m){
                return countSubarrays;
            }
        }

        return countSubarrays;

    }

    int splitArray(vector<int>& nums, int m) {
        
        int maxele=INT_MIN,sum=0;
        for(int num:nums){
            maxele=max(maxele,num);
            sum+=num;
        }

        int start=maxele,end=sum;
        int minSum=sum;
        while(start<=end){
            int middle=start+(end-start)/2;
            int sumVal=isSumValueEnough(nums,middle,m);

            if(sumVal > m){
                start=middle+1;
            }
            else{
                minSum=min(minSum,middle);
                end=middle-1;
            }

        }
        return minSum;

    }
};