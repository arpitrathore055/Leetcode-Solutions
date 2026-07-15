class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> partitionsSize;
        map<char,int> charLastPosition;
        for(int i=0;i<s.length();i++){
            charLastPosition[s[i]]=i;
        }

        int startInd=0;
        int boundaryInd=charLastPosition[s[0]];
        for(int i=0;i<s.length();i++){

            boundaryInd=max(boundaryInd,charLastPosition[s[i]]);

            if(i==boundaryInd){

                partitionsSize.push_back(i-startInd+1);

                startInd=i+1;
            }
        }
        return partitionsSize;

    }
};
