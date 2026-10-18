class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        vector<int> taskExecutionOrder(tasks.size());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<tuple<int,int,int>> tasksList;
        for(int i=0;i<tasks.size();i++){
            int startTime=tasks[i][0];
            int processingTime=tasks[i][1];
            tasksList.push_back({startTime,processingTime,i});
        }
        
        sort(begin(tasksList),end(tasksList));
        long long currentTime=0;
        int tasksPointer=0;
        
        for(int i=0;i<tasks.size();i++){
            
            //check for currentTime will not be less than remaining non-reachable tasks, else update currentTime to match their startTime
            if(pq.empty() && tasksPointer < tasksList.size() && currentTime < get<0>(tasksList[tasksPointer])){
                currentTime=get<0>(tasksList[tasksPointer]);
            }
            
            //checking and pushing all valid tasks in min heap
            while(tasksPointer < tasksList.size() && get<0>(tasksList[tasksPointer]) <= currentTime){
                pq.push({get<1>(tasksList[tasksPointer]),get<2>(tasksList[tasksPointer])});
                tasksPointer++;
            }
            
            pair<int,int> frontNode=pq.top();
            pq.pop();
            int minTaskProcessingTime=frontNode.first;
            int minTaskIndex=frontNode.second;
            
            currentTime+=minTaskProcessingTime;
            taskExecutionOrder[i]=minTaskIndex;
            
        }
        
        return taskExecutionOrder;
        
    }
};