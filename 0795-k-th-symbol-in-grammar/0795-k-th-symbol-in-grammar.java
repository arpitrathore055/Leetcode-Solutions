class Solution {
    public int kthGrammar(int n, int k) {
        
        if(n==1){
            if(k<1){
                return -1;
            }
            return 0;
        }
        int digitRec=kthGrammar(n-1,(k%2 != 0 )?((k/2)+1):(k/2));
        if(digitRec == 1 && (k%2)!= 0  || digitRec == 0 && (k%2)== 0){
            return 1;
        }
        else{
            return 0;
        }

    }
}