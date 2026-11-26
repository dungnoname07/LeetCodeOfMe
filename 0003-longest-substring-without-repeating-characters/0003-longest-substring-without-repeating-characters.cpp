class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int ans = 0;
        map<char, int> count;
        for (int i = 0; i < n; i++) {
            count[s[i]]++;
            while(count[s[i]] > 1) {
                count[s[l]] --;
                l++;
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};