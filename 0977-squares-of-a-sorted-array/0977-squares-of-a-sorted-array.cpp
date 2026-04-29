class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> answer(nums.size());
        int pointer=nums.size()-1;
        int start=0,end=nums.size()-1;
        while(start<=end){
            if((nums[start]*nums[start]) > (nums[end]*nums[end])){
                answer[pointer]=nums[start]*nums[start];
                start++;
            }
            else{
                answer[pointer]=nums[end]*nums[end];
                --end;
            }
            pointer--;
        }
        return answer;
    }
};