class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int count=0,n=nums.size();
        unordered_map<int,int> remainderPresence;
        remainderPresence[0]=1;
        int currSubarraySum=0;
        for(int i=0;i<n;i++){
            currSubarraySum+=nums[i];
            int targetRemainder=((currSubarraySum % k) + k) % k;
            if(remainderPresence.find(targetRemainder) != remainderPresence.end()){
                count+=remainderPresence[targetRemainder];
            }
            remainderPresence[targetRemainder]++;
        }
        return count;
    }
};