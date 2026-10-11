class Solution {
public:
    int quickSelectionAlgo(vector<int>& nums, int start, int end, int targetIndex) {
        while (start <= end) {
            int randomIndex = start + rand() % (end - start + 1);
            int pivot = nums[randomIndex];

            int lt = start, i = start, gt = end;

            while (i <= gt) {
                if (nums[i] < pivot) {
                    swap(nums[lt++], nums[i++]);
                } 
                else if (nums[i] > pivot) {
                    swap(nums[i], nums[gt--]);
                } 
                else {
                    i++;
                }
            }

            if (targetIndex < lt) {
                end = lt - 1;
            } 
            else if (targetIndex > gt) {
                start = gt + 1;
            } 
            else {
                return nums[targetIndex];
            }
        }

        return -1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quickSelectionAlgo(nums, 0, nums.size() - 1, nums.size() - k);
    }
};