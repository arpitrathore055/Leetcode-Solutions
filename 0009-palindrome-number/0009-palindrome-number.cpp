class Solution {
public:
    bool isPalindrome(int x) {
         string s=to_string(x);
        bool is_palindrome=true;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=s[s.length()-1-i])
            {
                is_palindrome=false;
                break;
            }
        }
        return is_palindrome;
    }
};