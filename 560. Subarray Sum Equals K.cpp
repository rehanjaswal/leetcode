class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, preSum = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            if (preSum == k) count++;
            if (mp.contains(preSum - k)) count += mp[preSum - k];
            if (mp.contains(preSum)) mp[preSum]++;
            else mp[preSum] = 1;
        }
        return count;
    }
};