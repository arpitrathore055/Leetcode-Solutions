class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        int n=intervals.size();
        if(n == 1){
            return 1;
        }
        int noOfGroups=0,totalMergeIntervals=0;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];

            mp[start]+=1;
            mp[end+1]-=1;
        }
        for(auto& entry:mp){
            totalMergeIntervals+=entry.second;
            noOfGroups=max(noOfGroups,totalMergeIntervals);
        }
        return noOfGroups;

    }
};