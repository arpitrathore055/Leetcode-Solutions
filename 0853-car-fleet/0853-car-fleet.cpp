class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n=position.size();
        stack<double> st;
        int fleetCount=0;
        
        vector<pair<int,int>> cars(n);
        for(int i=0;i<n;i++){
            cars[i]={position[i],speed[i]};
        }
        
        sort(cars.begin(), cars.end(),
           [](const auto& a, const auto& b) {
               return a.first > b.first;
           });

        double prevTimeRequired=-1;
        
        for(int i=0;i<n;i++){
            
            double timeRequired=(double)(target-cars[i].first)/cars[i].second;
            
            if(timeRequired >prevTimeRequired){
                fleetCount++;
                prevTimeRequired=timeRequired;
            }
            
        }
        
        return fleetCount;
        
    }
};