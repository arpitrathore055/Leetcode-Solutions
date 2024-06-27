class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>umap;
        for(auto& time:times){
            int u=time[0];
            int v=time[1];
            int reqtime=time[2];
            umap[u].push_back({v,reqtime});
        }
        vector<int>reqTime(n+1,INT_MAX);
        set<pair<int,int>>st;
        reqTime[k]=0;
        st.insert({0,k});
        while(!st.empty()){
            auto& it=*st.begin();
            int vertex=it.second;
            int signalReachTime=it.first;
            st.erase(it);
            for(auto& v:umap[vertex]){
                int nextVertex=v.first;
                int nextVertexReachTime=v.second;
                
                if(signalReachTime+nextVertexReachTime < reqTime[nextVertex]){

                    if(reqTime[nextVertex]!=INT_MAX){
                        st.erase({reqTime[nextVertex],nextVertex});
                    }

                    reqTime[nextVertex]=signalReachTime+nextVertexReachTime;
                    st.insert({reqTime[nextVertex],nextVertex});
                }

            }
        }
        int minTimeReq=0;
        for(int i=1;i<n+1;i++){
            
            if(reqTime[i]==INT_MAX){
                return -1;
            }
            else{
                if(reqTime[i] > minTimeReq){
                    minTimeReq=reqTime[i];
                }
            }

        }
        return minTimeReq;
    }
};