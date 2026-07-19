class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> indices;

        int start=0;
        int end=numbers.size()-1;
        while(start <  end){
            int value= numbers[start]+numbers[end];
            if(value == target){
                return {start+1,end+1};
            }
            else if(value < target){
                start++;
            }
            else{
                end--;
            }
        }

        return {-1,-1};

    }
};