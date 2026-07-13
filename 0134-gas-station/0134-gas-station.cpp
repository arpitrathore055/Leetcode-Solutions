class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totalGasAvailable=accumulate(begin(gas),end(gas),0);
        int totalGasRequired=accumulate(begin(cost),end(cost),0);

        if(totalGasAvailable < totalGasRequired){
            return -1;
        }

        int currGasAvailable=0;
        int startIndex=0;
        for(int i=0;i<gas.size();i++){

            currGasAvailable += gas[i] - cost[i];

            if(currGasAvailable < 0){
                startIndex=i+1;
                currGasAvailable=0;
            }

        }
        return startIndex;

    }
};