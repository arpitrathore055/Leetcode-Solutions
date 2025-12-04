class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> groups;
        vector<vector<string>>ans;
        for(string& s:strs){

            vector<int>freq(26,0);
            for(int i=0;i<s.length();i++){
                freq[s[i]-'a']++;
            }
            string key="";
            for(int f:freq){
                key+=to_string(f)+",";
            }
            groups[key].push_back(s);
        }
        for(auto& it:groups){
            ans.push_back(it.second);
        }
        return ans;

    }
};