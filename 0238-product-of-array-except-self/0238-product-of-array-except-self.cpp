class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n=nums.size();
        vector<int> productExceptSelfArray(n);

        int leftPrefixValue=1;
        for(int  i=0;i<n;i++){
            productExceptSelfArray[i] = leftPrefixValue;
            leftPrefixValue *= nums[i];
        }

        int rightPrefixValue=1;
        for(int i=n-1;i>=0;i--){
            productExceptSelfArray[i] *= rightPrefixValue;
            rightPrefixValue *= nums[i];
        }

        return productExceptSelfArray;

    }
};
