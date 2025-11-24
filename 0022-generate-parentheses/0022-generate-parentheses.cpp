class Solution {
public:

    void possibleValidCombinations(string& currStr,vector<string>& combinations,int& n,int countOpening,int countClosing){

        if(currStr.size() == (n*2)){
            combinations.push_back(currStr);
            return;
        }

        if(countOpening < n){
            currStr.push_back('(');
            possibleValidCombinations(currStr,combinations,n,countOpening+1,countClosing);
            currStr.pop_back();
        }
        if(countClosing < countOpening){
            currStr.push_back(')');
            possibleValidCombinations(currStr,combinations,n,countOpening,countClosing+1);
            currStr.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        
        vector<string> combinations;
        string currStr="";
        possibleValidCombinations(currStr,combinations,n,0,0);
        return combinations;

    }
};