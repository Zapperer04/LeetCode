class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin() , nums.end());
        int maxLen = 0;
        for(int x : st){
            if(st.find(x-1) != st.end()){
                continue;
            }
            int current = x;
            int count = 1;
            while(st.find(current+1) != st.end()){
                count += 1;
                current++;
            }
            maxLen = max(maxLen, count);    
        }
        return maxLen;
    }
};