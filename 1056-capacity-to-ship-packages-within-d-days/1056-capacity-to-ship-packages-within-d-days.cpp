class Solution {
public:

    bool checkValidWeightCapacity(vector<int>& weights,int& middle,int& days){

        int expectedDaysCount=0;
        int currDaysCount=0;
        for(int weight:weights){

            currDaysCount+=weight;
            if(currDaysCount > middle ){
                expectedDaysCount++;
                currDaysCount=0;
                currDaysCount+=weight;
            }
            if(expectedDaysCount > days){
                return false;
            }

        }
        if(currDaysCount <= middle){
            expectedDaysCount++;
        }
        return (expectedDaysCount <= days);

    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        auto result=max_element(weights.begin(),weights.end());
        int start=*result;
        int end=accumulate(weights.begin(),weights.end(),0);

        int minWeightCapacity=end;

        while(start<=end){

            int middle=start+(end-start)/2;
            bool isWeightCapacityEnough=checkValidWeightCapacity(weights,middle,days);

            if(!isWeightCapacityEnough){
                start=middle+1;
            }
            else{
                minWeightCapacity=min(minWeightCapacity,middle);
                end=middle-1;
            }

        }

        return minWeightCapacity;

    }
};