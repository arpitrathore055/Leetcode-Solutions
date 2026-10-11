class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
      
        int rows=matrix.size();
        int cols=matrix[0].size();
        
        int maxArea=0;
        
        vector<int> colWiseSum(cols,0);
        
        for(int row=0;row<rows;row++){
            
            for(int i=0;i<cols;i++){
                if (matrix[row][i] == '1')
                    colWiseSum[i]++;
                else
                    colWiseSum[i] = 0;
            }
            
            stack<int> st;
            
            for(int i=0;i<=cols;i++){
                
                int value=(i != cols)?colWiseSum[i]:0;
                while(!st.empty() && colWiseSum[st.top()] >= value){
                    
                    int height=colWiseSum[st.top()];
                    st.pop();
                    int leftBoundary=(!st.empty())?st.top():-1;
                    int rightBoundary=i;
                    int width=rightBoundary-leftBoundary-1;
                    
                    maxArea=max(maxArea,(height*width));
                    
                }
                
                if(i == cols){
                    continue;
                }
                
                st.push(i);
                
            }
            
        }
        
        return maxArea;
        
    }
};