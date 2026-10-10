#include<bits/stdc++.h>
class Solution {
public:
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int rows=matrix.size();
        int cols=matrix[0].size();
        int subMatricesCount=0;
        
        for(int leftCol=0;leftCol<cols;leftCol++){
            
            vector<int> rowwiseSum(rows,0);
            for(int rightCol=leftCol;rightCol<cols;rightCol++){
                
                //filling in rowwise sum
                for(int row=0;row<rows;row++){
                    rowwiseSum[row]+=matrix[row][rightCol];
                }
                
                unordered_map<int,int> prefixOccurrences;
                prefixOccurrences[0]=1;
                int currPrefixSum=0;
                
                for(int i=0;i<rows;i++){
                    
                    currPrefixSum+=rowwiseSum[i];
                    
                    int targetPrefix=currPrefixSum-target;
                    
                    if(prefixOccurrences.find(targetPrefix) != prefixOccurrences.end()){
                        
                        subMatricesCount+=prefixOccurrences[targetPrefix];
                        
                    }
                        
                    prefixOccurrences[currPrefixSum]++;
                    
                }
                
            }
            
        }
        return subMatricesCount;
        
    }
};