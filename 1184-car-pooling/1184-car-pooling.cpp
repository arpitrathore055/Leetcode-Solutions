class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int n=trips.size();
        if(n == 0){
            return true;
        }
        if(n == 1 && trips[0][0] <= capacity){
            return true;
        }

        bool result=true;
        int totalPassengerCount=0;
        map<int,pair<int,int>>mp;
        for(int i=0;i<n;i++){
            int passenger=trips[i][0];
            int start=trips[i][1];
            int end=trips[i][2];
            if(mp.find(start) != mp.end()){
                mp[start].first+=passenger;
            }
            else{
                mp[start]=make_pair(passenger,0);
            }
            if(mp.find(end) != mp.end()){
                mp[end].second+=passenger;
            }
            else{
                mp[end]=make_pair(0,passenger);
            }
        }
        pair<int,int> tmp;
        for(auto& entry:mp){
            tmp=entry.second;
            totalPassengerCount=totalPassengerCount-tmp.second+tmp.first;
            if(totalPassengerCount > capacity){
                return false;
            }
        }
        return true;

    }
};