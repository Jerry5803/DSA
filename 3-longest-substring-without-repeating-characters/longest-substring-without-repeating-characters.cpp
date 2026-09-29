class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int left = 0;
        int longest = 0;

        for (int right = 0; right < n; right++) {
            if (mp.count(s[right]) && mp[s[right]] >= left) {
                left = mp[s[right]] + 1;
            }
            mp[s[right]] = right;
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};