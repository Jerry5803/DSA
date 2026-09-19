class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        int longest = 1;
        unordered_set<int> mp;
        for (int num : nums) {
            mp.insert(num);
        }

        for (auto it : mp) {
            if (mp.find(it - 1) == mp.end()) {
                int start = it;
                int count = 1;
                while (mp.find(start + 1) != mp.end()) {
                    count++;
                    start++;
                }
                longest = max(count, longest);
            }
        }
        return longest;
    }
};