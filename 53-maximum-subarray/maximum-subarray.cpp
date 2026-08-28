class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int left = 0;
        int maxSum = nums[0];
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            if (sum < nums[right]) {
                sum = nums[right];
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};