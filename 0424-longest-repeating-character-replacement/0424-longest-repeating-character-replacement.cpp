class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int sLen=s.length();
        unordered_map<char,int> mp;
        
        int start=0;
        int end=0;
        int maxSubstringLen=0;
        int maxCharacterCount=0;
        
        for(;end<sLen;end++){
            //updation
            mp[s[end]]++;
            maxCharacterCount=max(maxCharacterCount,mp[s[end]]);
            int windowSize=end-start+1;
            
            //invalidation
            while((windowSize - maxCharacterCount) > k){
                mp[s[start]]--;
                start++;
                windowSize=end-start+1;
            }
            
            //answer compute
            maxSubstringLen=max(maxSubstringLen,windowSize);
            
        }
        
        return maxSubstringLen;
        
    }
};