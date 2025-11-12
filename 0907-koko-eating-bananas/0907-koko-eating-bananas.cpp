class Solution {
public:

    int calculateTimeRequired(vector<int>& piles,int& middle,int& h){
        int timeRequired=0;
        for(int pile:piles){
            timeRequired+=((pile%middle) == 0)? (pile/middle):(pile/middle)+1;
            if(timeRequired > h){
                return timeRequired;
            }
        }
        return timeRequired;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        auto result=minmax_element(piles.begin(),piles.end());
        int start=1;
        int end=*result.second;
        int k=INT_MAX;

        while(start<=end){
            int middle = start + (end - start) / 2;
            int timeRequired=calculateTimeRequired(piles,middle,h);
            if(timeRequired > h){
                start=middle+1;
            }
            else{
                k=min(k,middle);
                end=middle-1;
            }

        }

        return k;

    }
};