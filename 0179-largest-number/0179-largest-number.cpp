#include <string>
class Solution {
public:
    string largestNumber(vector<int>& nums) {

        string largestNumber = "";
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });

        if (nums[0] == 0) {
            return "0";
        }

        for (auto& ele : nums) {
            largestNumber += to_string(ele);
        }
        return largestNumber;
    }
};