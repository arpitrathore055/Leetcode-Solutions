class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n=position.size();
        stack<double> st;
        int fleetCount=0;
        
        unordered_map<int,int> carSpeed;
        for(int i=0;i<n;i++){
            carSpeed[position[i]]=speed[i];
        }
        
        sort(position.begin(),position.end(),[](const int& a,const int& b){
           return a>b; 
        });
        
        for(int i=0;i<n;i++){
            
            double timeRequired=(double)(target-position[i])/carSpeed[position[i]];
            
            if(!st.empty() && st.top() >= timeRequired){
                continue;
            }
            
            st.push(timeRequired);
            
        }
        
        fleetCount=st.size();
        return fleetCount;
        
    }
};