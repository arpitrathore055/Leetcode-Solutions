class Solution {
public:
    int findTheLongestSubstring(string s) {

        unordered_map<int,int> prefix;
        prefix[0]=-1;
        int mask=0;
        int maxLen=0;

        for(int j=0;j<s.length();j++){

            char ch=s[j];

            if(ch == 'a') mask^= (1<<0);
            else if(ch == 'e') mask^= (1<<1);
            else if(ch == 'i') mask^= (1<<2);
            else if(ch == 'o') mask^= (1<<3);
            else if(ch == 'u') mask^= (1<<4);
            
            if(prefix.find(mask) != prefix.end()){
                maxLen=max(maxLen,j-prefix[mask]);
            }
            else{
                prefix[mask]=j;
            }

        }

        return maxLen;

    }
};