class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int j = nums[0];
        int maxDiff = -1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > j ){
                maxDiff = max(maxDiff, nums[i] - j); 
            }
            else{
                j = nums[i];
            }
            
        }
        return maxDiff;
    }
};