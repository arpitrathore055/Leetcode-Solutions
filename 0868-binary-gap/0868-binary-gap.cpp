class Solution {
public:

    int binaryGap(int n) {

       int currPos=0;
       int lastPos=-1;
       int maxGap=0;
       while(n>0){
        if((n&1) == 1){
            if(lastPos != -1){
                maxGap=max(maxGap,currPos-lastPos);
            }
            lastPos=currPos;
        }
        n>>=1;
        currPos++;
       } 
        return maxGap;
    }
};