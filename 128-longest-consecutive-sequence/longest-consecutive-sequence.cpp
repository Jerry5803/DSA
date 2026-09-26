class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        int longest = 1;
        unordered_set<int> st;

        for (int num : nums) {
            st.insert(num);
        }

        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int start = it;
                int count = 1;

                while (st.find(start + 1) != st.end()) {
                    count += 1;
                    start += 1;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};