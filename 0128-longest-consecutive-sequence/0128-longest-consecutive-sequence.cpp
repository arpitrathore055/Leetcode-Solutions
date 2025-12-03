class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> presence(nums.begin(),nums.end());

        int maxSize=0;
        for(int n:presence){

            if(presence.find(n-1) == presence.end()){

                int count=0;
                int i=1;
                while(presence.find(n+i) != presence.end()){
                    count++;
                    i++;
                }
                maxSize=max(maxSize,count+1);

            }

        }
        return maxSize;

    }
};