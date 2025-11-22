class Solution {
public:
    string removeStars(string s) {
        
        string ans="";
        for(char ch:s){
            if(ch != '*'){
                ans.push_back(ch);
            }
            else{
                if(!ans.empty()){
                    ans.pop_back();
                }
            }
        }
        return ans;
    }
};