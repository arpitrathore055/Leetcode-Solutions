class Solution {

    vector<pair<int,int>>dsu;

public:

    void Union(int u,int v){
        int uparent=find(u);
        int vparent=find(v);
        if(uparent==vparent){
            return;
        }
        if(dsu[uparent].second > dsu[vparent].second){
            dsu[vparent].first=uparent;
        }
        else if (dsu[uparent].second < dsu[vparent].second){
            dsu[uparent].first=vparent;
        }
        else{
            dsu[vparent].first=uparent;
            dsu[uparent].second++;
        }
    }

    int find(int u){
        if(dsu[u].first==u){
            return u;
        }
        return dsu[u].first=find(dsu[u].first);
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        dsu.resize(n);
        for(int i=0;i<n;i++){
            dsu[i].first=i;
            dsu[i].second=1;
        }

        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            if(find(u)==find(v)){
                continue;
            }
            Union(u,v);
        }

        return (find(source)==find(destination))?true:false;
    }
};