class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> nonOverlappingIntervals;

        intervals.push_back(newInterval);
        sort(begin(intervals),end(intervals),[](vector<int>& a,vector<int>& b){
            return a[0] < b[0];
        });

        int prevStart=intervals[0][0];
        int prevEnd=intervals[0][1];
        for(int i=1;i<intervals.size();i++){

            int currStart=intervals[i][0];
            int currEnd=intervals[i][1];

            if(currStart <= prevEnd){
                prevStart=min(prevStart,currStart);
                prevEnd=max(prevEnd,currEnd);
            }
            else{
                nonOverlappingIntervals.push_back({prevStart,prevEnd});
                prevStart=currStart;
                prevEnd=currEnd;
            }

        }
        nonOverlappingIntervals.push_back({prevStart,prevEnd});

        return nonOverlappingIntervals;

    }
};
