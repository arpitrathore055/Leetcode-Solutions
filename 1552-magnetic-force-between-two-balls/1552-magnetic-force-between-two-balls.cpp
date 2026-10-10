class Solution {
public:
    
    bool canPlaceBalls(vector<int>& position, int m, int distanceBetweenBalls) {
    int ballsPlaced = 1;
    int lastPosition = position[0];

    for (int i = 1; i < position.size(); i++) {
        if (position[i] - lastPosition >= distanceBetweenBalls) {
            ballsPlaced++;
            lastPosition = position[i];

            if (ballsPlaced == m) {
                return true;
            }
        }
    }

    return false;
}
    
    int maxDistance(vector<int>& position, int m) {
        
        sort(position.begin(),position.end());
        int n=position.size();
        int start=1;
        int end=position[n-1]-position[0];

        int maxValidDistancePositioning=INT_MIN;
        
        while(start<=end){
            
            int middle=(end-start)/2 + start;
            if(canPlaceBalls(position,m,middle)){
                maxValidDistancePositioning=max(maxValidDistancePositioning,middle);
                start=middle+1;
            }
            else{
                end=middle-1;
            }
            
        }
        
        return maxValidDistancePositioning;
        
    }
};