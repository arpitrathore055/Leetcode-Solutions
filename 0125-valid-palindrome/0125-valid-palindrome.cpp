class Solution {
public:
    bool isPalindrome(string s) {
        
        int n=s.length();
        if(n == 0 || n == 1){
            return true;
        }
        int start=0,end=n-1;
        while(start<=end){

            if(!isalnum((unsigned char)s[start])){
                ++start;
            }
            else if(!isalnum((unsigned char)s[end])){
                --end;
            }
            else if(tolower(s[start]) == tolower(s[end])){
                ++start;
                --end;
            }
            else{
                return false;
            }

        }
        return true;

    }
};