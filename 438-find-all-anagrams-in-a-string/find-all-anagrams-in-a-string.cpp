class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        vector<int> ans;
        for(char ch : p){
            freq1[ch - 'a']++;
        }
        int left = 0;
        for(int right=0; right<s.size(); right++){
            freq2[s[right]- 'a']++;
            while(right - left + 1 > p.size()){
                freq2[s[left] - 'a']--;
                left++;
            }
            if(freq1 == freq2){
                ans.push_back(left);
            }
        }
        return ans;
    }
};