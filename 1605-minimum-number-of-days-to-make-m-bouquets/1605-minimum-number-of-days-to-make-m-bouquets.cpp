class Solution {
public:

    bool consecutiveBloomFlowersCount(vector<int>bloomDay,int middle,int m,int k){
        int blcount=0,count=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=middle){
                blcount++;
            }
            else{
                count+=blcount/k;
                blcount=0;
            }
        }
        count+=blcount/k;
        if(count>=m){
            return true;
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        
        if ((long long)bloomDay.size() < (long long)m * (long long)k) {
            return -1;
        }


        auto result=minmax_element(bloomDay.begin(),bloomDay.end());
        int start=*result.first;
        int end=*result.second;
        int minDay=*result.second;

        while(start<=end){

            int middle=(start)+(end-start)/2;
            bool consecutiveBloomFlowers=consecutiveBloomFlowersCount(bloomDay,middle,m,k);

            if(!consecutiveBloomFlowers){
                start=middle+1;
            }
            else{
                minDay=min(minDay,middle);
                end=middle-1;
            }

        };
        return minDay;

    }
};