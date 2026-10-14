class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int validStartIndex=-1;
        
        int totalGasAvailableAtStation=accumulate(gas.begin(),gas.end(),0);
        int totalGasNeededToTravel=accumulate(cost.begin(),cost.end(),0);
        
        if(totalGasAvailableAtStation < totalGasNeededToTravel){
            return validStartIndex;
        }
        
        int currGasInTank=0;
        validStartIndex=0;
        
        for(int i=0;i<gas.size();i++){
            
            currGasInTank+=gas[i]-cost[i];
            
            if(currGasInTank < 0){
                validStartIndex=i+1;
                currGasInTank=0;
            }
            
        }
        
        return validStartIndex;
        
    }
};