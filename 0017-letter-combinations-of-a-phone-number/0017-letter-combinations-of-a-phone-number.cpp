class Solution {
public:
    
    void backtrack(int startInd,int n,string& str,string& currString,vector<string>& collections,map<char,string>& numberMap){
        
        //basecase
        if(currString.size() == n){
            collections.push_back(currString);
            return;
        }
        
        //choices
        string characters=numberMap[str[startInd]];
        for(int choice=0;choice<characters.size();choice++){
            
            //prunning
            
            //apply and undo
            currString.push_back(characters[choice]);
            
            backtrack(startInd+1,n,str,currString,collections,numberMap);
            
            currString.pop_back();
            
        }
        
    }

    vector<string> letterCombinations(string digits) {
        
        vector<string> collections;
        string currString="";
        int startInd=0;
        int n=digits.size();
        
        map<char,string> numberMap;
        numberMap['2']="abc";
        numberMap['3']="def";
        numberMap['4']="ghi";
        numberMap['5']="jkl";
        numberMap['6']="mno";
        numberMap['7']="pqrs";
        numberMap['8']="tuv";
        numberMap['9']="wxyz";
        
        backtrack(startInd,n,digits,currString,collections,numberMap);
        return collections;

    }
};