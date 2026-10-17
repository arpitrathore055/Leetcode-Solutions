class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        priority_queue<int,vector<int>> pq;
        int capitalPointer=0;
        vector<pair<int,int>> projects;
        for(int i=0;i<capital.size();i++){
            projects.push_back({capital[i],profits[i]});
        }
        
        sort(begin(projects),end(projects));
        
        while(k--){
            
            while(capitalPointer<capital.size() && projects[capitalPointer].first<=w){
                int profit=projects[capitalPointer].second;
                pq.push(profit);
                capitalPointer++;
            }

            if(pq.empty()){
                break;
            }
            
            int maxProfit=pq.top();
            pq.pop();
            w+=maxProfit;
            
        }
    
        return w;
    
    }
};