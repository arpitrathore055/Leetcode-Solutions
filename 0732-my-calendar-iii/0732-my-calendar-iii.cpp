class MyCalendarThree {
public:

    int bookingsCount;
    vector<vector<int>> bookings;
    map<int,int>mp;

    MyCalendarThree() {
        bookingsCount=0;
    }
    
    int book(int startTime, int endTime) {
        if(bookingsCount == 0){
            bookingsCount++;
            bookings.push_back({startTime,endTime});
            mp[startTime]+=1;
            mp[endTime]-=1;
            return 1;
        }
        mp[startTime]+=1;
        mp[endTime]-=1;
        int currBookingsCount=0,activeBookings=0;
        for(auto& entry:mp){
            currBookingsCount+=entry.second;
            activeBookings=max(activeBookings,currBookingsCount);
        }
        bookings.push_back({startTime,endTime});
        bookingsCount++;
        return activeBookings;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */