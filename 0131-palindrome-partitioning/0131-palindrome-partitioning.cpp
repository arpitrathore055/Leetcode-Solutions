class Solution {
public:
    
    bool isPalindrome(string strValue){
        
        int start=0;
        int end=strValue.size()-1;
        
        while(start <= end){
            if(strValue[start] != strValue[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
        
    }

    void backtrack(int startInd,int n,string& s,vector<string>& currPartitions,vector<vector<string>>& partitionCollection){
        
        //basecase
        if(startInd == n){
            partitionCollection.push_back(currPartitions);
            return;
        }
        
        //choices
        for(int choice=startInd;choice<n;choice++){
            
            //prunning
            string strValue=s.substr(startInd,choice-startInd+1);
            if(!isPalindrome(strValue)){
                continue;
            }
            
            //apply and undo
            currPartitions.push_back(strValue);
            
            backtrack(choice+1,n,s,currPartitions,partitionCollection);
            
            currPartitions.pop_back();
            
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> partitionCollection;
        vector<string> currPartitions;

        int n=s.length();
        int startInd=0;
        backtrack(startInd,n,s,currPartitions,partitionCollection);
        return partitionCollection;

    }
};