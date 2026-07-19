class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.length() > s2.length()){
            return false;
        }

        vector<int> characterFreq(26,0);

        for(auto character:s1){
            characterFreq[character-'a']++;
        }

        int start=0;
        int end=0;

        // Build first window
        for(;end<s1.length();end++){
            characterFreq[s2[end]-'a']--;
        }

        int matchedCharacterCount=0;

        for(int i=0;i<26;i++){
            if(characterFreq[i]==0){
                matchedCharacterCount++;
            }
        }

        if(matchedCharacterCount==26){
            return true;
        }

        for(;end<s2.length();end++,start++){

            // Add new character
            characterFreq[s2[end]-'a']--;

            if(characterFreq[s2[end]-'a']==0){
                matchedCharacterCount++;
            }
            else if(characterFreq[s2[end]-'a']==-1){
                matchedCharacterCount--;
            }

            // Remove old character
            characterFreq[s2[start]-'a']++;

            if(characterFreq[s2[start]-'a']==0){
                matchedCharacterCount++;
            }
            else if(characterFreq[s2[start]-'a']==1){
                matchedCharacterCount--;
            }

            if(matchedCharacterCount==26){
                return true;
            }
        }

        return false;
    }
};