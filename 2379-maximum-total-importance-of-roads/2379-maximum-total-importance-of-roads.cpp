class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<int>>umap;
        vector<int>vertexImp(n,0);
        for(auto& road:roads){
            int u=road[0];
            int v=road[1];
            umap[u].push_back(v);
            umap[v].push_back(u);
        }
        set<pair<int,int>,greater<pair<int,int>>>st;//childrenCount,vertex
        for(int i=0;i<umap.size();i++){
            st.insert({umap[i].size(),i});
        }   
        long long int impValue=n,totalImportance=0;
        while(!st.empty()){
            auto& it=*st.begin();
            int vertex=it.second;
            vertexImp[vertex]=impValue;
            impValue--;
            st.erase(it);
        }
        for(int i=0;i<umap.size();i++){
            for(auto& v:umap[i]){
                if(i > v){
                    continue;
                }
                totalImportance+=vertexImp[i]+vertexImp[v];
            }
        }
        return totalImportance;
    }
};