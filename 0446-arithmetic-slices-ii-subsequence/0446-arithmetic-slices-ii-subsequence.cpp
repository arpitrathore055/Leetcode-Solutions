class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int result=0;
        unordered_map<long,int> helper[nums.size()];
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                long diff=(long)nums[i]-nums[j];
                auto itr=helper[j].find(diff);
                int countFromPrev=itr==end(helper[j]) ?0: itr->second;

                helper[i][diff]+=countFromPrev+1;
                result+=countFromPrev;
            }
        }
        return result;
    }
};