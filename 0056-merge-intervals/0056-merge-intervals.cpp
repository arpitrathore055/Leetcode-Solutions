class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if(intervals.empty()){
            return {};
        }        

        vector<vector<int>> mergedIntervals;
        sort(intervals.begin(),intervals.end());

        vector<int>currInterval;
        currInterval=intervals[0];

        for(int i=1;i<intervals.size();i++){

            if(intervals[i][0] <= currInterval[1]){
                currInterval[1]=max(currInterval[1],intervals[i][1]);
            }
            else{
                mergedIntervals.push_back(currInterval);
                currInterval=intervals[i];
            }
        }
        mergedIntervals.push_back(currInterval);
        return mergedIntervals;

    }
};