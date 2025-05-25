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

    static bool comp(string a,string b){
        return a.length() < b.length();
    }

    int longestStrChain(vector<string>& words) {
        
        vector<int>dp(1001,1);
        sort(words.begin(),words.end(),comp);
        int maxValue=1;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(isPredecessor(words[j],words[i])){
                    dp[i]=max(dp[j]+1,dp[i]);
                    maxValue=max(maxValue,dp[i]);
                }
            }
        }
        return maxValue;

    }
};