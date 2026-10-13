class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
  
        vector<vector<int>> skylineBuildings;
        
        map<int,vector<pair<int,int>>> events;
        
        for(auto& building:buildings){
            
            int start=building[0];
            int end=building[1];
            int height=building[2];
            
            events[start].push_back({height,1});
            events[end].push_back({height,-1});
            
        }
        
        multiset<int,greater<int>> ms={0};
        int previousHeight=0;
        
        for(auto& [coordinate,eventAtCoordinate]:events){
            
            for(auto& [height,type]:eventAtCoordinate){
                
                if(type == 1){
                    ms.insert(height);
                }
                else{
                    auto it=ms.find(height);
                    if(it!=ms.end()){
                        ms.erase(it);
                    }
                }
                
            }
            
            int currHeight=*ms.begin();
            if(currHeight != previousHeight){
                skylineBuildings.push_back({coordinate,currHeight});
                previousHeight=currHeight;
            }
            
        }
        
        return skylineBuildings;
        
    }
};