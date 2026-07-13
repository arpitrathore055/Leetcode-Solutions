class Solution {
public:
    int jump(vector<int>& nums) {
        
        int minJumps=0;
        int insideBoundary=0;
        int farthestBoundary=0;

        for(int i=0;i<nums.size()-1;i++){

            farthestBoundary=max(farthestBoundary,i + nums[i]);

            if(i == insideBoundary){
                minJumps++;
                insideBoundary=farthestBoundary;
            }

        }

        return minJumps;

    }
};
