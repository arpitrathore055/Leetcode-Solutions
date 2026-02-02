class NumMatrix {
public:
    vector<vector<int>> prefix;

    NumMatrix(vector<vector<int>>& matrix) {
        prefix.assign(200, vector<int>(200, 0));
        prefix[0][0] = matrix[0][0];
        for (int i = 1; i < matrix.size(); i++) {
            prefix[i][0] = matrix[i][0] + prefix[i-1][0];
        }
        for (int j = 1; j < matrix[0].size(); j++) {
            prefix[0][j] = matrix[0][j] + prefix[0][j-1];
        }
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                prefix[i][j] = matrix[i][j] + prefix[i - 1][j] +
                               prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = prefix[row2][col2];

        if (row1 > 0)
            total -= prefix[row1 - 1][col2];

        if (col1 > 0)
            total -= prefix[row2][col1 - 1];

        if (row1 > 0 && col1 > 0)
            total += prefix[row1 - 1][col1 - 1];

        return total;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */