class Solution {
public:

    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void backtrack(string s,int start,vector<string>& path,vector<vector<string>>& result){

        //base case
        if(start == s.length()){
            result.push_back(path);
            return;
        }

        //choices
        for(int end=start;end<s.length();end++){

            //pruning condition
            if(!isPalindrome(s,start,end)){
                continue;
            }

            //apply
            path.push_back(s.substr(start,end-start+1));
            //recursion
            backtrack(s,end+1,path,result);
            //undo
            path.pop_back();

        }

    }

    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> result;
        vector<string> path;
        backtrack(s,0,path,result);
        return result;

    }
};