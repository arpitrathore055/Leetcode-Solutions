class Solution {
    typedef pair<int,pair<int,int>> p;
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<p,vector<p>,greater<p>>pq;
        unordered_map<string,bool>inmst;
        for(auto& point:points){
            string key=to_string(point[0])+to_string(point[1]);
            inmst[key]=false;
        }
        pq.push({0,{points[0][0],points[0][1]}});
        int cost=0;
        while(!pq.empty()){
            p frontPoint=pq.top();
            pq.pop();
            
            int weight=frontPoint.first;
            int xpoint=frontPoint.second.first;
            int ypoint=frontPoint.second.second;
            string key=to_string(xpoint)+to_string(ypoint);

            if(inmst[key]){
                continue;
            }

            inmst[key]=true;
            cost+=weight;

            for(auto& point:points){
                int x1=point[0];
                int y1=point[1];
                string key=to_string(x1)+to_string(y1);
                if(!inmst[key]){
                    int costToConnect=abs(xpoint-x1)+abs(ypoint-y1);
                    pq.push({costToConnect,{x1,y1}});
                }
            }
        }
        return cost;
    }
};