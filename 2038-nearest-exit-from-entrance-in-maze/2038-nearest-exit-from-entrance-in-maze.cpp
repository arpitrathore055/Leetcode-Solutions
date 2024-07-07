class Solution {
    
    vector<vector<int>>directions{{-1,0},{0,-1},{1,0},{0,1}};

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row=maze.size();
        int col=maze[0].size();
        queue<pair<int,int>>qu;
        qu.push(make_pair(entrance[0],entrance[1]));
        maze[entrance[0]][entrance[1]]='+';
        int steps=0;
        while(!qu.empty()){
            int size=qu.size();
            for(int k=0;k<size;k++){
                pair<int,int> frontPair=qu.front();
                qu.pop();
                int old_i=frontPair.first;
                int old_j=frontPair.second;
                if((frontPair!=make_pair(entrance[0],entrance[1])) && (old_i==0 || old_i==row-1 || old_j==0 || old_j==col-1)){
                    return steps;
                }
                for(auto& direction:directions){
                    int new_i=old_i+direction[0];
                    int new_j=old_j+direction[1];
                    if(new_i >=0 && new_i<row && new_j >=0 && new_j < col && maze[new_i][new_j]!='+'){
                        qu.push(make_pair(new_i,new_j));
                        maze[new_i][new_j]='+';
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};