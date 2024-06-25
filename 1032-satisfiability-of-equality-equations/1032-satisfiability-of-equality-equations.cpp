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

    bool equationsPossible(vector<string>& equations) {
        dsu.resize(26);
        for(int i=0;i<26;i++){
            dsu[i].first=i;
            dsu[i].second=1;
        }
        for(auto equation:equations){
            int u=(int)(equation[0])-97;
            int v=(int)(equation[3])-97;
            if(equation[1]=='='){
                Union(u,v);
            }
        }
        for(auto equation:equations){
            int u=(int)(equation[0])-97;
            int v=(int)(equation[3])-97;
            if(equation[1]=='!'){
                int uParent=find(u);
                int vParent=find(v);
                if(uParent==vParent){
                    return false;
                }
            }
        }
        return true;
    }
};