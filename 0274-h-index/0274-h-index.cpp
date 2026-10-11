class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        sort(citations.begin(),citations.end());
        
        int start=0;
        int n=citations.size();
        int end=citations.size()-1;
        int maxHIndex=0;
        
        while(start<=end){
            
            int middle=(end - start)/2 + start;
            int countOfGreaterElements=n-middle;
            
            if(citations[middle]>=countOfGreaterElements){
                maxHIndex=countOfGreaterElements;
                end=middle-1;
            } 
            else{
                start=middle+1;
            }
            
        }
        
        return maxHIndex;
        
    }
};