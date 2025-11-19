class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows=matrix[0].size();
        int cols=matrix.size();
        int start=0;
        int end=(rows*cols)-1;

        while(start<=end){
            int middle=start+(end-start)/2;
            if(matrix[middle/rows][middle%rows] == target){
                return true;
            }
            else if(matrix[middle/rows][middle%rows] > target){
                end=middle-1;
            }
            else{
                start=middle+1;
            }
        }
        return false;
    }
};