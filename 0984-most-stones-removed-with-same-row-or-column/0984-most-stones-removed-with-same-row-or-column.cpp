class Solution {
public:

    void dfsTraversal(int index,vector<vector<int>>&stones,vector<bool>&visited){
        visited[index]=true;
        for(int i=0;i<stones.size();i++){
            int row=stones[index][0];
            int col=stones[index][1];
            if(!visited[i] && (stones[i][0]==row || stones[i][1]==col)){
                dfsTraversal(i,stones,visited);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        vector<bool>visited(stones.size(),false);
        int n=stones.size(),groups=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfsTraversal(i,stones,visited);
                ++groups;
            }
        }
        return n-groups;
    }
};