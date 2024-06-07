class Solution {
public:

    string fetchRootFromWord(string individualWord,unordered_set<string>& uset){
        for(int i=1;i<individualWord.length();i++){
            if(uset.find(individualWord.substr(0,i))!=uset.end()){
                return individualWord.substr(0,i);
            }
        }
        return individualWord;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> uset;
        for(auto word:dictionary){
            uset.insert(word);
        }
        stringstream ss(sentence);
        string individualWord;
        string finalSentence="";
        while(ss >> individualWord){
            finalSentence+=fetchRootFromWord(individualWord,uset)+" ";
        }
        finalSentence.pop_back();
        return finalSentence;
    }
};