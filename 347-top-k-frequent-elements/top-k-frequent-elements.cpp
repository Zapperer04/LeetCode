class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> store;
        for(auto& pair : mp){
            store.push_back({pair.second, pair.first});
        }
        sort(store.begin(), store.end());
        vector<int> ans;
        for(int i=store.size()-1; i>=(int)store.size()-k; i--){
            ans.push_back(store[i].second);
        }
        return ans;
    }
};