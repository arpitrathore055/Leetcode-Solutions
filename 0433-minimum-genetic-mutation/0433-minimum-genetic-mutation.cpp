class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> setBank(bank.begin(),bank.end());
        unordered_set<string> alreadyMutatedString;
        queue<string>qu;
        qu.push(startGene);
        alreadyMutatedString.insert(startGene);
        int level=0;
        while(!qu.empty()){
            int size=qu.size();
            for(int i=0;i<size;i++){
                string currString=qu.front();
                qu.pop();
                if(currString == endGene){
                    return level;
                }
                for(char choices:"ACGT"){
                    for(int j=0;j<currString.length();j++){
                        string mutatedString=currString;
                        mutatedString[j]=choices;
                        if(alreadyMutatedString.find(mutatedString)==alreadyMutatedString.end() && setBank.find(mutatedString)!=setBank.end()){
                            qu.push(mutatedString);
                            alreadyMutatedString.insert(mutatedString);
                        }
                    }
                }
            }
            ++level;
        }
        return -1;
    }
};