class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        stack<int> st;
        
        int maxArea=0;
        
        for(int i=0;i<=n;i++){
            
            int value=(i != n)?heights[i]:0; 
            while(!st.empty() && heights[st.top()] > value){
                
                int height=heights[st.top()];
                st.pop();
                int leftBoundary=(!st.empty())?st.top():-1;
                int rightBoundary=i;
                int width=rightBoundary-leftBoundary-1;
                int area=height*width;
                
                maxArea=max(maxArea,area);
                
            }

            if(i==n){
                continue;
            }

            st.push(i);
            
        }
        
        return maxArea;
        
    }
};