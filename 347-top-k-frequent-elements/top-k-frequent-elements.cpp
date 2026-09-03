class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto x : freq) {
            bucket[x.second].push_back(x.first);
        }

        vector<int> ans;

        for (int i = nums.size(); i >= 1; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};