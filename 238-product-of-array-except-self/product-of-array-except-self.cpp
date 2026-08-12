class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size() , 1);
        int leftProduct = 1;
        int rightProduct = 1;
        for(int i=0; i<nums.size(); i++){
            ans[i] = leftProduct;
            leftProduct *= nums[i];
        }
        for(int j=nums.size()-1; j>=0; j--){
            ans[j] *= rightProduct;
            rightProduct *= nums[j];
        }
        return ans;
    }
};