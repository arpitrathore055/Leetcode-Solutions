class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> umap;
        for(auto i:edges){
            vector<int> temp=i;
            int u=temp[0];
            int v=temp[1];
            umap[u].push_back(v);
            umap[v].push_back(u);
        }
        int center=0;
        for(auto i:umap)
        {
            if(i.second.size()==(umap.size()-1)){
                center=i.first;
                break;
            }
        }
        return center;
    }
};