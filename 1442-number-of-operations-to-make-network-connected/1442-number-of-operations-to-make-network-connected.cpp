class Solution {

    vector<pair<int,int>>dsu;

public:

    int find(int u){
        if(dsu[u].first==u){
            return u;
        }
        return dsu[u].first=find(dsu[u].first);
    }
    
    void Union(int u,int v){
        int uParent=find(u);
        int vParent=find(v);
        if(uParent==vParent){
            return;
        }
        if(dsu[uParent].second > dsu[vParent].second){
            dsu[vParent].first=uParent;
        }
        else if(dsu[uParent].second < dsu[vParent].second){
            dsu[uParent].first=vParent;
        }
        else{
            dsu[vParent].first=uParent;
            dsu[uParent].second++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        dsu.resize(n);
        int countWire=0,countDisComponent=n;
        for(int i=0;i<n;i++){
            dsu[i].first=i;
            dsu[i].second=1;
        }      
        unordered_map<int,vector<int>>umap;
        for(auto x:connections){
            int u=x[0];
            int v=x[1];
            umap[u].push_back(v);
            umap[v].push_back(u);
        }
        for(int i=0;i<umap.size();i++){
            for(auto v:umap[i]){
                if(i>v){
                    continue;
                }
                if(find(i)==find(v)){
                    countWire++;
                }
                else{
                    Union(i,v);
                    countDisComponent--;
                }
            }
            cout<<endl;
        }
        return (countWire>=countDisComponent-1)?countDisComponent-1:-1;
    }
};