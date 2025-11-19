class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int start=0,end=cols-1;
        while(start<rows && end>=0){
            if(matrix[start][end] == target){
                return true;
            }
            else if(matrix[start][end] > target){
                --end;
            }
            else{
                ++start;
            }
        }
        return false;
    }
};