class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        unordered_set<int> s2;

        for (int num : nums1) {
            s1.insert(num);
        }
        for (int num : nums2) {
            s2.insert(num);
        }

        vector<int> ans;

        for (auto it : s1) {
            if (s2.count(it)) {
                ans.push_back(it);
            }
        }
        return ans;
    }
};