class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inDegree(numCourses,0);
        unordered_map<int,vector<int>>graph;
        for(auto x:prerequisites){
            int u=x[1],v=x[0];
            graph[u].push_back(v);
            inDegree[v]++;
        }
        queue<int>qu;
        int count=0;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                qu.push(i);
            }
        }
        while(!qu.empty()){
            int size=qu.size();
            for(int i=0;i<size;i++){
                int frontVertex=qu.front();
                qu.pop();
                count++;
                for(auto v:graph[frontVertex]){
                    inDegree[v]--;
                    if(inDegree[v]==0){
                        qu.push(v);
                    }
                }
            }
        }
        return count == numCourses;
    }
};