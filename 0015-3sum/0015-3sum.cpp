class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> tripletsCollection;
        int n = nums.size();

        sort(begin(nums), end(nums));

        for (int i = 0; i < n - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int target = -nums[i];
            int start = i + 1;
            int end = n - 1;

            if ((nums[start] + nums[start + 1]) > target || (nums[end] + nums[end - 1]) < target) {
                continue;
            }

            while (start < end) {
                int value = nums[start] + nums[end];
                if (value == target) {
                    tripletsCollection.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                    while (start < end && nums[start] == nums[start - 1]) {
                        start++;
                    }
                    while (start < end && nums[end] == nums[end + 1]) {
                        end--;
                    }
                } else if (value < target) {
                    start++;
                } else {
                    end--;
                }
            }
        }

        return tripletsCollection;
    }
};
