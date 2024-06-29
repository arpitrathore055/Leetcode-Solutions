class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>reqTime(n+1,INT_MAX);
        reqTime[k]=0;
        for(int i=0;i<=n-1;i++){
            for(auto& time:times){
                int u=time[0];
                int v=time[1];
                int weight=time[2];
                if(reqTime[u]!=INT_MAX && reqTime[u]+weight < reqTime[v]){
                    reqTime[v]=reqTime[u]+weight;
                }
            }
        }
        int maxReqTime=0;
        for(int i=1;i<=n;i++){
            if(reqTime[i]==INT_MAX){
                return -1;

            }
            if(reqTime[i] > maxReqTime){
                maxReqTime=reqTime[i];
            }
        }
        return maxReqTime;
    }
};