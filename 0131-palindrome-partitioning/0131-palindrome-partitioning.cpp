class Solution {
public:
    
    bool isPalindrome(string s){
        
        int start=0;
        int end=s.length()-1;
        while(start<=end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }

        return true;
        
    }
    
    void backtrack(string s,vector<vector<string>>& validPartitions,vector<string>& currPartition,int start,int end){
        
        if(start == end){
            validPartitions.push_back(currPartition);
            return;
        }
        
        for(int i=start;i<end;i++){
            
            string currString=s.substr(start,i-start+1);
            if(!isPalindrome(currString)){
                continue;
            }
            
            currPartition.push_back(currString);
            
            backtrack(s,validPartitions,currPartition,i+1,end);
            
            currPartition.pop_back();
            
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        
        int n=s.length();
        vector<vector<string>> validPartitions;
        vector<string> currPartition;
        
        backtrack(s,validPartitions,currPartition,0,n);
        
        return validPartitions;
        
    }
};