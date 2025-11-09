class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n=people.size();
        vector<int> flowersCount(n);
        map<int,int>mp;
        for(auto& it:flowers){
            mp[it[0]]+=1;
            mp[it[1]+1]-=1;
        }
        int currFlowersCount=0;
        for(auto& entry:mp){
            currFlowersCount+=entry.second;
            entry.second=currFlowersCount;
        }

        for(int i=0;i<n;i++){
            auto it=mp.lower_bound(people[i]);
            if(it->first == people[i]){
                flowersCount[i]=it->second;
            }
            else if(it->first > people[i] && it != mp.begin()){
                --it;
                flowersCount[i]=it->second;
            }
            else{
                
            }
        }
        return flowersCount;
    }
};