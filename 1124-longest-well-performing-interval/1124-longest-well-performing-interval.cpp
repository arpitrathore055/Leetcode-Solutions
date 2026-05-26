class Solution {
public:
    int longestWPI(vector<int>& hours) {
        
        unordered_map<int,int> prefix;
        int maxLen=0;
        int prefixSum=0;

        for(int j=0;j<hours.size();j++){

            if(hours[j] > 8){
                prefixSum+=1;
            }
            else{
                prefixSum+=-1;
            }

            if(prefixSum > 0){
                maxLen=j+1;
            }
            else{
                int requiredPrefixSum=prefixSum-1;
                if(prefix.find(requiredPrefixSum) != prefix.end()){
                    maxLen=max(maxLen,j-prefix[requiredPrefixSum]);
                }
            }

            if(prefix.find(prefixSum) == prefix.end()){
                prefix[prefixSum]=j;
            }

        }

        return maxLen;

    }
};