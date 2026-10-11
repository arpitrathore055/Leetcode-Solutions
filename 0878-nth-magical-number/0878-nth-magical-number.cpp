class Solution {
public:
    
    const long long MOD=1e9+7;
    
    int nthMagicalNumber(int n, int a, int b) {
        
        long long start=min(a,b);
        long long end=1LL*min(a,b) * n;
        long long count=0;
        long long magicalNumber=end;
        
        long long lcmValue=1LL*a/gcd(a,b)*b;
        
        while(start<=end){
            
            long long middle=(end-start)/2 + start;
            count=(middle/a)+(middle/b)-(middle/lcmValue);
            if(count>=n){
                magicalNumber=middle;
                end=middle-1;
            }
            else{
                start=middle+1;
            }
            
        }
        
        return magicalNumber%MOD;
        
    }
};