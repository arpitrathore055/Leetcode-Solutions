class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int l=0,r=0,n=s.length();
        unordered_map<char,int> umap;
        int maxSubarrayLen=0,duplicatesCount=0;
        for(;r<n;r++){

            //updation part
            if(++umap[s[r]] == 2){
                duplicatesCount++;
            }

            //invalid scenerio part
            while(duplicatesCount > 0 && l<=r){
                if(--umap[s[l]] ==1){
                    duplicatesCount--;
                }
                l++;
            }

            //ans computation part
            maxSubarrayLen=max(maxSubarrayLen,(r-l+1));
        }
        return maxSubarrayLen;

    }
};