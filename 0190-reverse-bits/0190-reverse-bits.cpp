class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        int size=32;
        while(size--){
            //fetching last bit
            int lastBit=n&1;

            //add to the ans
            ans=ans<<1;
            ans=ans | lastBit;
        
            //remove last bit from n
            n=n>>1;
        }
        return ans;
    }
};