class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        int s=bookings.size();
        vector<int>freq(n,0);
        for(int i=0;i<s;i++){
            freq[bookings[i][0]-1]+=bookings[i][2];
            if(bookings[i][1] != n){
                freq[bookings[i][1]]-=bookings[i][2];
            }
            
        }
        int seatsCount=0;
        for(int i=0;i<n;i++){
            seatsCount+=freq[i];
            freq[i]=seatsCount;
        }
        return freq;
    }
};