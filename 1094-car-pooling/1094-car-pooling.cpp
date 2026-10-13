class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
            
        int n=trips.size();
        bool carPoolingPossible=true;
        vector<int> differenceArray(1001);
        
        for(auto& trip:trips){
            int personCount=trip[0];
            int tripStart=trip[1];
            int tripEnd=trip[2];
            
            differenceArray[tripStart]+=personCount;
            differenceArray[tripEnd]-=personCount;
            
        }

        int currPersonCount=0;
        for(auto& personCount:differenceArray){
            
            if(currPersonCount + personCount > capacity){
                return false;
            }
            currPersonCount=currPersonCount + personCount;
            
        }
        
        return carPoolingPossible;
    }
};