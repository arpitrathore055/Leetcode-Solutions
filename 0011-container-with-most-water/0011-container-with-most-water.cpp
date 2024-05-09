class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea=0,area=0,low=0,high=height.size()-1;
        while(low<high){
            area=(high-low)*min(height[low],height[high]);
            if(maxarea<area){
                maxarea=area;
            }
            if(height[low]<height[high]){
                low++;
            }
            else{
                high--;
            }
        }
        return maxarea;
    }
};