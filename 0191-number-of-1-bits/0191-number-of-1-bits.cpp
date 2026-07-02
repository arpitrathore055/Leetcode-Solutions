class Solution {
public:
    int hammingWeight(int n) {
        
        int countSetBits=0;
        while(n!=0){
            //fetch last bit
            int lastBit=n&1;

            //count++ if set
            if(lastBit == 1){
                countSetBits++;
            }

            //remove last bit from n
            n=n>>1;

        }
        return countSetBits;
    }
};