#include<bits/stdc++.h>
class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> partitionsSize;

        map<char,pair<int,int>> charPosition;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(!charPosition.count(ch)){
                charPosition[ch].first=i;
            }
            charPosition[ch].second=i;
        }

        vector<pair<int,int>> intervals;
        for(auto entry:charPosition){
            intervals.push_back({entry.second.first,entry.second.second});
        }

        sort(begin(intervals),end(intervals));

        int prevStart=intervals[0].first;
        int prevEnd=intervals[0].second;
        for(int i=1;i<intervals.size();i++){

            int currStart=intervals[i].first;
            int currEnd=intervals[i].second;

            if(currStart <= prevEnd){
                prevStart=min(prevStart,currStart);
                prevEnd=max(prevEnd,currEnd);
            }
            else{
                int currPartitionSize=prevEnd - prevStart+1;
                partitionsSize.push_back(currPartitionSize);
                prevStart=currStart;
                prevEnd=currEnd;
            }

        }
        partitionsSize.push_back(prevEnd-prevStart+1);

        return partitionsSize;

    }
};
