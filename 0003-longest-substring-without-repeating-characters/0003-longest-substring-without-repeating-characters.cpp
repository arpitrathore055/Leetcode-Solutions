class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int low=0,high=0,maxCount=0,currCount=0;
        vector<int> freq(256,0);
        while(high<s.length()){
            if(freq[(s[high])]==0){
                freq[(s[high])]++;
                currCount++;
                high++;
            }
            else{
                maxCount=max(maxCount,currCount);
                freq[(s[low])]--;
                currCount--;
                low++;
            }
        }
        maxCount=max(maxCount,currCount);      
        return maxCount;
    }
};