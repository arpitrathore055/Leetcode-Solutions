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
        vector<vector<int>> bucket(nums.size()+1);
        for(auto entry:freq){
            bucket[entry.second].push_back(entry.first);
        }

        for(int i=nums.size();i>=0;i--){
            
            if(k <= 0){
                break;
            }

            if(!bucket[i].empty()){
                int size=bucket[i].size();
                if(size >= k){
                    topElements.insert(topElements.end(),bucket[i].begin(),bucket[i].begin()+k);
                    k=size-k;
                }
                else{
                    topElements.insert(topElements.end(),bucket[i].begin(),bucket[i].end());
                    k=k-size;
                }
            }

        }
        
        return topElements;
    }
};