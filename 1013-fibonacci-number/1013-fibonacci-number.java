class Solution {
    // private int dp(31,-1);
    public int fib(int n) {
        if(n<=1){
            return n;
        } 
        return fib(n-1)+fib(n-2);
    }
}