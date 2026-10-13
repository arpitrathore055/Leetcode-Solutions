class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    
        int removedIntervalsCount=0;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
            if(a[1] == b[1]){
                return a[0] < b[0];
            } 
            return a[1] < b[1];
        });
        
        int start=intervals[0][0];
        int end=intervals[0][1];
        
        for(int i=1;i<n;i++){
            
            int currStart=intervals[i][0];
            int currEnd=intervals[i][1];
            
            if(currStart < end){
                removedIntervalsCount++;
                continue;
            }
            
            start=currStart;
            end=currEnd;
            
        }
        
        return removedIntervalsCount;
        
    }
};