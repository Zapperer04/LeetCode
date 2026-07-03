class Solution {
public:
    int firstOcc(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;
        int ans = -1;
        while(left <= right){
            int mid = left + (right-left) / 2;
            if(target == nums[mid]){
                ans = mid;
                right = mid - 1;
            } else if(target > nums[mid]){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }   
        return ans;
    }
    int secOcc(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;
        int ans = -1;
        while(left<= right){
            int mid = left + (right - left) / 2;
            if(target == nums[mid]){
                ans = mid;
                left = mid + 1;
            } else if(target > nums[mid]){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOcc(nums, target);
        int second = secOcc(nums, target);
        return {first, second};
    }
};