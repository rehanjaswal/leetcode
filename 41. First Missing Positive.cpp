class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // place every number x at index x - 1 (one based indexing)
        for (int i = 0; i < n; i++) {
            while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // first position where the expexted number is missing
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        // if 1...n are all present in nums, n + 1 will be the smallest positive
        return n + 1;
    }
};