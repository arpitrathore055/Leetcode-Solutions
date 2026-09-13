class Solution {
public:
    string minWindow(string s, string t) {
        
        int sLen=s.length();
        int tLen=t.length();
        
        if(sLen < tLen){
            return "";
        }
        
        unordered_map<char,int> required;
        unordered_map<char,int> available;
        
        for(char ch:t){
            required[ch]++;
        }
        
        int minSubstringLen=INT_MAX;
        int startIndex=0;
        int availableCharacters=0;
        int requiredCharacters=required.size();
        int start=0;
        int end=0;
        
        for(;end<sLen;){
            
            //updation
            if(++available[s[end]] == required[s[end]]){
                availableCharacters++;
            }
            ++end;
            
            //invalidation
            //answer compute
            while(availableCharacters == requiredCharacters){
                
                if((end -start) < minSubstringLen){
                    minSubstringLen=end-start;
                    startIndex=start;    
                }
                //start removing from left
                if(--available[s[start]] < required[s[start]]){
                    availableCharacters--;
                }
                start++;
                
            }
            
            
        }
        return (minSubstringLen == INT_MAX)?"":s.substr(startIndex,minSubstringLen);
        
    }
};