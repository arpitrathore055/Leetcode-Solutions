class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int> freq(26,0);
        int maxSize=0;
        int maxFreq=0;
        int i=0,j=0;
        for(;j<s.length();j++){

            //updation
            freq[s[j]-'A']++;
            maxFreq=max(maxFreq,freq[s[j]-'A']);
            int windowLength=j-i+1;

            //check for invalid condition and based on that we'll reduce window size
            if((windowLength - maxFreq) > k){

                while((windowLength - maxFreq) > k){
                    freq[s[i]-'A']--;
                    ++i;
                    //maxFreq=max(maxFreq,freq[s[i]-'a']);
                    //we have to look for a solution so that again iteration over freq completely is avoided

                    windowLength=j-i+1;
                }

            }

            //if everything fine, ans(maxSize) updation
            maxSize=max(maxSize,windowLength);

        }

        return maxSize;

    }
};