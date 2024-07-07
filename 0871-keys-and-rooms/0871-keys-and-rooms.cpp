class Solution {
public:

    void canVisitEveryRoom(int source,vector<vector<int>>&rooms,vector<bool>&isOpen,unordered_map<int,vector<int>>&umap){
        isOpen[source]=true;
        for(auto& v:umap[source]){
            if(!isOpen[v]){
                canVisitEveryRoom(v,rooms,isOpen,umap);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int,vector<int>>umap;
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                umap[i].push_back(rooms[i][j]);
            }
        }
        vector<bool>isOpen(rooms.size(),false);
        isOpen[0]=true;
        canVisitEveryRoom(0,rooms,isOpen,umap);
        for(int i=0;i<rooms.size();i++){
            if(isOpen[i]==false){
                return false;
            }
        }
        return true;
    }
};