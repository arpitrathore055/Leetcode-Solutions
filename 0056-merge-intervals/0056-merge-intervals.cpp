class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
  
        vector<vector<int>> nonOverLappingIntervals;
        
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
           if(a[0] == b[0]){
            return a[1]<b[1];
           }
           return  a[0] < b[0];
        });
        
        int start=intervals[0][0];
        int end=intervals[0][1];
        
        for(int i=1;i<=intervals.size();i++){
            
            int currentStart=(i != intervals.size())?intervals[i][0]:INT_MAX;
            int currentEnd=(i != intervals.size())?intervals[i][1]:INT_MAX;
            
            if(currentStart <= end){
                
                start=min(start,currentStart);
                end=max(end,currentEnd);
                
            }
            else{
                nonOverLappingIntervals.push_back({start,end});
                start=currentStart;
                end=currentEnd;
            }
            
        }
        
        return nonOverLappingIntervals;
        
    }
};