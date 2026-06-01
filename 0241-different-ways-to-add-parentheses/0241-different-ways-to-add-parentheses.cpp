class Solution {

vector<int> dp[21][21];
string str;

vector<int> combine(vector<int> leftPart,vector<int> rightPart,char op){
    vector<int> finalAns;
    for(auto lValue:leftPart){
        for(auto rValue:rightPart){
            int computedValue=0;
            if(op == '+'){
                computedValue=lValue+rValue;
            }
            else if(op == '-'){
                computedValue=lValue-rValue;
            }
            else{
                computedValue=lValue*rValue;
            }
            finalAns.push_back(computedValue);
        }
    }
    return finalAns;
}

vector<int> rec(int l,int r){
    //pruning

    //base case
    if(l == r){
        return {str[l] - '0'};
    }

    //caching
    if(!dp[l][r].empty()){
        return dp[l][r];
    }

    //compute
    vector<int>ans;
    bool containsOperator=false;
    for(int k=l;k<r;k++){

        if(str[k] == '+' || str[k] == '-' || str[k] == '*'){
            containsOperator=true;
            char op=str[k];
            vector<int> mergedValues=combine(rec(l,k-1),rec(k+1,r),op);
            ans.insert(ans.end(),mergedValues.begin(),mergedValues.end());
        }

    }

    if(!containsOperator){
        return {stoi(str.substr(l,r-l+1))};
    }

    //save and return
    return dp[l][r]=ans;
}

public:
    vector<int> diffWaysToCompute(string expression) {
        
        str=expression;
        for(int i=0;i<21;i++){
            for(int j=0;j<21;j++){
                dp[i][j]={};
            }
        }
        return rec(0,str.length()-1);
    }
};