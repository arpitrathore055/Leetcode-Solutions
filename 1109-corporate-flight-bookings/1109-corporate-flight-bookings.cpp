class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        vector<int> seatsReservedPerFlight(n+2);
        
        for(auto booking:bookings){
            int startFlight=booking[0];
            int endFlight=booking[1];
            int seatsCount=booking[2];
            
            seatsReservedPerFlight[startFlight]+=seatsCount;
            seatsReservedPerFlight[endFlight+1]-=seatsCount;
        }
        
        int prefixSum=0;
        for(int i=1;i<=n;i++){
            seatsReservedPerFlight[i]+=prefixSum;
            prefixSum=seatsReservedPerFlight[i];
            // cout<<"index: "<<i<<" -> "<<seatsReservedPerFlight[i]<<endl;
        }
        
        return vector<int>(
            seatsReservedPerFlight.begin()+1,
            seatsReservedPerFlight.begin()+n+1
        );
        
    }
};