class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
      
        vector<int> smallestValidRange={-1000000,1000000};
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        
        int minVal=INT_MAX;
        int maxVal=INT_MIN;
        int minValListIndex=0;
        int minValElementIndex=0;
        
        for(int i=0;i<nums.size();i++){
            
            int listElementIndex=0;
            int listIndex=i;
            int elementVal=nums[listIndex][listElementIndex];
            
            maxVal=max(maxVal,elementVal);
            pq.push({elementVal,listElementIndex,listIndex});
            
        }
        
        while(true){
            
            //calculate or get minimum, maximum and minimum containing listIndex
            vector<int> frontNode=pq.top();
            pq.pop();
            
            minVal=frontNode[0];
            minValElementIndex=frontNode[1];
            minValListIndex=frontNode[2];
            
            if(maxVal - minVal < smallestValidRange[1] - smallestValidRange[0] || minVal < smallestValidRange[0] && maxVal - minVal == smallestValidRange[1] - smallestValidRange[0]){
                smallestValidRange[0]=minVal;
                smallestValidRange[1]=maxVal;
            }
            
            int nextElementIndex=minValElementIndex+1;
            if(nextElementIndex >= nums[minValListIndex].size()){
                break;
            }
            
            int nextElementVal=nums[minValListIndex][nextElementIndex];
            maxVal=max(maxVal,nextElementVal);
            pq.push({nextElementVal,nextElementIndex,minValListIndex});
            
        }
        
        return smallestValidRange;
        
    }
};