class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int minLen = INT_MAX;
        int sum = 0;
        for(int right = 0; right<nums.size(); right++){
            sum = sum + nums[right];
            while(sum >= target){
                minLen = min(minLen, right-left+1);
                sum = sum - nums[left];
                left++;
            }
        }
        if(minLen == INT_MAX){
            return 0;
        }
        else {
            return minLen;
        }
    }
};