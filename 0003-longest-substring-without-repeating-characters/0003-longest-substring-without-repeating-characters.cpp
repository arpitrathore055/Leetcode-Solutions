class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int sLen=s.length();
        unordered_set<char> st;
        
        int start=0;
        int end=0;
        int maxSubstringLen=0;
        
        for(;end<sLen;){
            
            if(!st.count(s[end])){
                st.insert(s[end]);
                ++end;
            }
            else{
                maxSubstringLen=max(maxSubstringLen,end-start);
                while(st.count(s[end]) && start<end){
                    st.erase(s[start]);
                    start++;
                }
                
            }
        
        }
        maxSubstringLen=max(maxSubstringLen,end-start);
        return maxSubstringLen;
        
    }
};