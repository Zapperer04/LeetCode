class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }
        for(auto const& pair : mp){
            if(pair.second == 1){
                return pair.first;
            }
        }
        return -1;
    }
};