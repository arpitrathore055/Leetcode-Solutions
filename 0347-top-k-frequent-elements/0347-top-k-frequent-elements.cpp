class Solution {
public:

    struct Compare{

        bool operator()(const pair<int,int>& a,const pair<int,int>& b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first < b.first;
        }

    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> topElements;
        unordered_map<int,int> freq;
        for(auto num:nums){
            freq[num]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
        for(auto entry:freq){
            pq.push({entry.second,entry.first});
        }
        for(int i=0;i<k;i++){
            if(pq.empty()){
                break;
            }
            auto val=pq.top();
            pq.pop();
            topElements.push_back(val.second);
        }
        return topElements;
    }
};