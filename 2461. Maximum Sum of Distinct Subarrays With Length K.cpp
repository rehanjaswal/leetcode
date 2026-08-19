class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0, ans = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            freq[nums[i]]++;
        }
        if (freq.size() == k) ans = sum;
        
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i];
            sum -= nums[i - k];
            freq[nums[i]]++;
            freq[nums[i - k]]--;
            if (freq[nums[i - k]] == 0) freq.erase(nums[i - k]);
            if (freq.size() == k) ans = max(sum, ans);
        }
        return ans;
    }
};
