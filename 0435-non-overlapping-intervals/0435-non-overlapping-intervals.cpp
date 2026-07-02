class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
  
        sort(intervals.begin(), intervals.end(),[](const vector<int>& a, const vector<int>& b) {
            if (a[1] == b[1])
                return a[0] < b[0];

            return a[1] < b[1];
        });
        
        int prevEnd=intervals[0][1];
        int erasedIntervalsCount=0;
        for(int i=1;i<intervals.size();i++){
            
            int currStart=intervals[i][0];
            int currEnd=intervals[i][1];
            
            if(currStart < prevEnd){
                erasedIntervalsCount++;
            }
            else{
                prevEnd=currEnd;
            }
            
        }
        return erasedIntervalsCount;
    }
};