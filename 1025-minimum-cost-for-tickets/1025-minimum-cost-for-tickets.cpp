class Solution {
public:

    int dp[366];

    int findNextInd(int start,vector<int>& days,int end,int target){
        int n=end+1;
        while(start <= end){
            int middle=((end-start)/2)+start;
            if(days[middle] == target){
                return middle;
            }
            else if(days[middle] > target){
                end=middle-1;
            }
            else{
                start=middle+1;
            }
        }
        if(start == n){
            return -1;
        }
        return start;
    }

    int helper(int i,vector<int>& days,vector<int>& costs,int& n){
        if(i >= n || i<0){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int monthlyNextInd=findNextInd(i,days,n-1,days[i]+30),weeklyNextInd=findNextInd(i,days,n-1,days[i]+7);
        int dailyPass=costs[0]+helper(i+1,days,costs,n);
        int weeklyPass=costs[1]+helper(weeklyNextInd,days,costs,n);
        int monthlyPass=costs[2]+helper(monthlyNextInd,days,costs,n);
        return dp[i]=min(dailyPass,min(weeklyPass,monthlyPass));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        memset(dp,-1,sizeof(dp));
        return helper(0,days,costs,n);

    }
};