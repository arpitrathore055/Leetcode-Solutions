class Solution {
public:

    bool isPredecessor(string p,string c){
        int pl=p.length();
        int cl=c.length();
        if(cl-pl != 1){
            return false;
        }
        int i=0,j=0;
        while(i<pl && j<cl){
            if(p[i] == c[j]){
                i++;
            }
            j++;
        }

        return i == pl;
    }

    int dp[1001][1001];

    int solve(vector<string>& words,int ind,int prevind){
        if(ind >= words.size()){
            return 0;
        }
        if(prevind != -1 && dp[ind][prevind]!=-1){
            return dp[ind][prevind];
        }
        int take=0;
        if(prevind == -1 || isPredecessor(words[prevind],words[ind])){
            take=1+solve(words,ind+1,ind);
        }
        int skip=solve(words,ind+1,prevind);
        if(prevind != -1){
            return dp[ind][prevind]=max(take,skip);
        }
        return max(take,skip);
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string a,string b){
            return a.length() < b.length();
        });
        memset(dp,-1,sizeof(dp));
        return solve(words,0,-1);
    }
};