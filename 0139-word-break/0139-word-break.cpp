class Solution {
public:

    int dp[301];
    //denotes answer if string starting from index to n-1 can be segmented into a space-separated sequence of one or more dictionary words 

    bool solve(int index,int n,string s,set<string>& dict){
        //prunning
        //basecase
        if(index == n){
            return true;
        }

        //caching
        if(dp[index] != -1){
            return dp[index];
        }

        //ans compute
        bool ans=false;
        for(int start=index;start<n;start++){
            string str=s.substr(index,start-index+1);
            if(dict.count(str)){
                ans=ans || solve(start+1,n,s,dict);
            }
        }

        //save and return
        return dp[index]=ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        set<string> dict;
        for(auto word:wordDict){
            dict.insert(word);
        }
        return solve(0,n,s,dict);

    }
};