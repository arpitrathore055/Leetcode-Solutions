class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int count=0;
        for(char ch='a';ch<='z';ch++){

            int first=-1,last=-1;
            for(int i=0;i<s.length();i++){
                if(s[i] == ch){
                    if(first == -1){
                        first=i;
                    }
                    last=i;
                }
            }
            if((last-first) > 1){
                unordered_set<char> distinctChars;
                for(int i=first+1;i<last;i++){
                    distinctChars.insert(s[i]);
                }
                count+=distinctChars.size();
            }
        }
        return count;
    }
};