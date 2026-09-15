class Solution {
public:
    
    int getTargetParity(int parity,char ch){
        
        int bit=-1;
        if(ch == 'a'){
            bit=0;
        }
        else if(ch == 'e'){
            bit=1;
        }
        else if(ch == 'i'){
            bit=2;
        }
        else if(ch == 'o'){
            bit=3;
        }
        else if(ch == 'u'){
            bit=4;
        }
        else{
            return parity;
        }
        
        parity^= (1<<bit);
        
        return parity;
        
    }
    
    int findTheLongestSubstring(string s) {
  
        int sLen=s.length();
        unordered_map<int,int> parityMap;
        parityMap[0]=-1;
        
        int parity=0;
        int maxSubstringLen=0;
        
        for(int i=0;i<sLen;i++){
            
            parity=getTargetParity(parity,s[i]);
  
            if(parityMap.find(parity) == parityMap.end()){
                parityMap[parity]=i;
                continue;
            }
            
            maxSubstringLen=max(maxSubstringLen,(i-parityMap[parity]));
            
        }
        
        return maxSubstringLen;
        
    }
};