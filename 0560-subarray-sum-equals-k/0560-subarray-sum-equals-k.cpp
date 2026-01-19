class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count=0,n=nums.size();
        map<int,int> prefixPresence;
        prefixPresence[0]=1;
        int currSubarraySum=0;
        for(int i=0;i<n;i++){
            currSubarraySum+=nums[i];
            int prefixTarget=currSubarraySum-k;
            if(prefixPresence.find(prefixTarget)!=prefixPresence.end()){
                //found prefix target
                count+=prefixPresence[prefixTarget];
            }
            prefixPresence[currSubarraySum]++;
        }
        return count;
    }
};