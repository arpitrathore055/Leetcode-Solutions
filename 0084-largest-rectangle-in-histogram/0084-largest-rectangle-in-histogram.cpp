class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int maxAreaObtained=0;
        stack<int> monoIncStack;
        for(int i=0;i<=heights.size();i++){
            int currHeight=(i == heights.size())?0:heights[i];

            while(!monoIncStack.empty() && heights[monoIncStack.top()] > currHeight){
                //perform something
                int height=heights[monoIncStack.top()];
                monoIncStack.pop();
                int leftBoundary=(!monoIncStack.empty())? monoIncStack.top():-1;
                int rightBoundary=i;
                int width=rightBoundary - leftBoundary - 1;
                maxAreaObtained=max(maxAreaObtained,height * width);
            }

            if(i == heights.size()){
                continue;
            }
            monoIncStack.push(i);

        }
        return maxAreaObtained;
    }
};
