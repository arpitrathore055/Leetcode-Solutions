class Solution {
public:
    string minWindow(string s, string t) {
        
        if(t.length() > s.length()){
            return "";
        }
        unordered_map<char,int>required;
        unordered_map<char,int>window;
        for(auto& ch:t){
            required[ch]++;
        }
        int reqDistinctCh=required.size();
        int currDistinctCh=0;
        int minSubarrayLen=INT_MAX;
        int minSubarrayStartInd=0;
        int l=0,r=0;
        for(;r<s.length();r++){

            //updation part
            window[s[r]]++;
            if(required.find(s[r]) != required.end() && required[s[r]] == window[s[r]]){
                currDistinctCh++;
            }

            //minimum subarray part
            while(currDistinctCh == reqDistinctCh){

                if(r - l + 1 < minSubarrayLen){
                    minSubarrayLen = r - l + 1;
                    minSubarrayStartInd = l;
                }
                window[s[l]]--;
                if(required.find(s[l]) != required.end() && window[s[l]] < required[s[l]]){
                    currDistinctCh--;
                }
                l++;

            }

            //ans computation part

        }

        if(minSubarrayLen == INT_MAX){
            return "";
        }
        return s.substr(minSubarrayStartInd,minSubarrayLen);

    }
};