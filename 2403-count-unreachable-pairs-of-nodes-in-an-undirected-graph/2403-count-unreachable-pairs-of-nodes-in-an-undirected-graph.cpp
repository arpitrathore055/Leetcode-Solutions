class Solution {

    vector<pair<int,pair<int,int>>>dsu;//{ parent,rank,number of nodes within component }

public:

    void Union(int u,int v){
        int uParent=find(u);
        int vParent=find(v);
        cout<<"before "<<u<<" "<<v<<endl;
        if(uParent==vParent){
            return;
        }
        if(dsu[uParent].second.first > dsu[vParent].second.first){
            dsu[vParent].first=uParent;
            dsu[uParent].second.second+=dsu[vParent].second.second;
            dsu[vParent].second.second=0;
        }
        else if(dsu[uParent].second.first < dsu[vParent].second.first){
            dsu[uParent].first=vParent;           
            dsu[vParent].second.second+=dsu[uParent].second.second;
            dsu[uParent].second.second=0;
        }
        else{
            dsu[uParent].first=vParent;
            dsu[vParent].second.first++;
            dsu[vParent].second.second+=dsu[uParent].second.second;
            dsu[uParent].second.second=0;
        }
    }

    int find(int v){
        if(dsu[v].first==v){
            return v;
        }
        return dsu[v].first=find(dsu[v].first);
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        dsu.resize(n);
        for(int i=0;i<n;i++){
            dsu[i].first=i;
            dsu[i].second={1,1};
        }
        map<int,vector<int>>umap;
        long long int countUnreachableEdges=0;
        for(auto vec:edges){
            int u=vec[0];
            int v=vec[1];
            umap[u].push_back(v);
            umap[v].push_back(u);
        }
        for(int i=0;i<umap.size();i++){
            for(auto v:umap[i]){
                if(i > v){
                    continue;
                }
                if(find(i)!=find(v)){
                    Union(i,v);
                }
            }
        }
        int excludingVertices=0;
        for(int i=0;i<n;i++){
            cout<<i<<"--> "<<dsu[i].second.second<<endl;
            if(dsu[i].second.second!=0){
                countUnreachableEdges+=dsu[i].second.second * (long long int)((n-excludingVertices) - dsu[i].second.second);
                excludingVertices+=dsu[i].second.second;
            }
        }
        return countUnreachableEdges;
    }
};