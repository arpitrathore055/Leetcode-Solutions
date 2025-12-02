class Solution {
public:

    void reverseString(string& s,int start,int end){

        while(start<end){
            swap(s[start],s[end]);
            start++;end--;
        } 

    }

    string reverseWords(string s) {
        
        int n=s.length();
        int i=0,j=0;
        //checking for any leading spaces
        while(j<n && s[j]==' '){
            ++j; 
        }
        //shifting every character of string after removing leading spaces
        while(j<n){
            if(s[j]!=' '){
                s[i++]=s[j++];
            }
            else{
                s[i++]=' ';
                while(j<n && s[j]==' '){
                    ++j;
                }
            }
        }
        //checking for trailing white spaces
        while(i>0 && s[i-1]==' '){
            --i;
        }

        s.resize(i);
        //till now, we have received clean string and now starting with reversal
        reverse(s.begin(),s.end());

        i=0,j=0;
        for(;j<s.length();j++){
            if(s[j]==' '){
                reverseString(s,i,j-1);
                i=j+1;
            }
        }
        reverseString(s,i,j-1);
        return s;

    }
};