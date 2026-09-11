class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> result;
        map<vector<char>,vector<string>> groupedAnagrams;
        
        for(string st:strs){
            
            vector<char> stringKey(27,0);
            for(auto ch:st){
                stringKey[ch-'a']++;
            }    
            
            groupedAnagrams[stringKey].push_back(st);
            
        }
        for(auto res:groupedAnagrams){
            result.push_back(res.second);
        }
        
        return result;
        
    }
};