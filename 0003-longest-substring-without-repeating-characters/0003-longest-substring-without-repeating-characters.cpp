// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
        
//         int sLen=s.length();
//         unordered_set<char> st;
        
//         int start=0;
//         int end=0;
//         int maxSubstringLen=0;
        
//         for(;end<sLen;){
            
//             if(!st.count(s[end])){
//                 st.insert(s[end]);
//                 ++end;
//             }
//             else{
//                 maxSubstringLen=max(maxSubstringLen,end-start);
//                 while(!st.count(s[end])){
//                     st.erase(s[start]);
//                     start++;
//                 }
                
//             }
            
        
//         }
        
//         return maxSubstringLen;
        
//     }
// };


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int sLen=s.length();
        unordered_map<char,int> lastSeen;
        
        int start=0;
        int end=0;
        int maxSubstringLen=0;
        
        for(;end<sLen;){
            
            if(lastSeen.count(s[end])){
                start=max(start,lastSeen[s[end]]+1);
            }
            
            lastSeen[s[end]]=end;
            
            maxSubstringLen=max(maxSubstringLen,end-start+1);
            ++end;
            
        }
        
        return maxSubstringLen;
        
    }
};