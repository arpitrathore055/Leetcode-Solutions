#include<bits/stdc++.h>
class Solution {
public:

    bool isCountPrime(int count){

        if(count<=1){
            return false;
        }
        if(count<=3){
            return true;
        }
        if((count%2) == 0 || (count%3) == 0){
            return false;
        }
        for(int i=5;i*i<=count;i+=6){
            if((count%i) == 0 || (count%(i+2)) == 0){
                return false;
            }
        }
        return true;

    }

    int popcount(int n) {
        int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }

    int countPrimeSetBits(int left, int right) {
        
        int count=0;
        for(int i=left;i<=right;i++){

            //get count of set bits
            int setBitCount=popcount(i);

            //check if prime count, increment count
            if(isCountPrime(setBitCount)){
                ++count;
            }

        }
        return count;

    }
};