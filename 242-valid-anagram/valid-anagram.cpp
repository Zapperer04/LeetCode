class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq1(26,0);
        for(char ch : s){
            freq1[ch - 'a']++;
        }
        for(char ch : t){
            freq1[ch - 'a']--;
        }
        for(int count : freq1){
            if(count != 0){
                return false;
            }
        }
        return true;
    }
};