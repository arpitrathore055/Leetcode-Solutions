class MyCalendar {
public:

    int bookingsCount;
    vector<vector<int>> bookings;
    map<int,int>mp;

    MyCalendar() {
        bookingsCount=0;
    }
    
    bool book(int startTime, int endTime) {

        if(bookingsCount == 0){
            bookingsCount++;
            bookings.push_back({startTime,endTime});
            mp[startTime]+=1;
            mp[endTime]-=1;
            return true;
        }
        mp[startTime]+=1;
        mp[endTime]-=1;
        int currBookingsCount=0;
        for(auto& entry:mp){
            currBookingsCount+=entry.second;
            if(currBookingsCount > 1){
                mp[startTime]-=1;
                mp[endTime]+=1;
                return false;
            }
        }
        bookings.push_back({startTime,endTime});
        bookingsCount++;
        return true;

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */