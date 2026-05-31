class Solution {

string str;
vector<int> dp[21][21];

vector<int> combine(vector<int> leftPart,vector<int> rightPart,char op){
    vector<int> ans;
    for(auto lValue:leftPart){
        for(auto rValue:rightPart){
            int finalValue=0;
            if(op == '+'){
                finalValue=lValue + rValue;
            }
            else if(op == '-'){
                finalValue=lValue - rValue;
            }
            else{
                finalValue=lValue * rValue;
            }
            ans.push_back(finalValue);
        }
    }
    return ans;
}

vector<int> rec(int l,int r){
    //pruning;

    //base case
    if(l == r){
        return {str[l] - '0'};
    }

    //caching
    if(!dp[l][r].empty()){
        return dp[l][r];
    }

    //compute
    bool containsOperator=false;
    vector<int> ans;
    for(int k=l;k<r;k++){
        if(str[k] == '+' || str[k] == '-' || str[k] == '*'){
            containsOperator=true;
            char op=str[k];
            vector<int> temp = combine(rec(l,k-1),rec(k+1,r),op);
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
    }

    if(!containsOperator){
        return dp[l][r]={stoi(str.substr(l,r-l+1))};
    }

    //save and return
    return dp[l][r]=ans;
}

public:
    vector<int> diffWaysToCompute(string expression) {
        str=expression;
        for(int i = 0; i < 21; i++){
            for(int j = 0; j < 21; j++){
                dp[i][j].clear();
            }
        }
        return rec(0,str.length()-1);  
    }
};