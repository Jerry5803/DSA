class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;

        for (int x : nums) {
            int left = 0;
            int right = tails.size();

            while (left < right) {
                int mid = left + (right - left) / 2;

                if (tails[mid] >= x) {
                    right = mid;
                }
                else {
                    left = mid + 1;
                }
            }
            if (left == tails.size()) {
                tails.push_back(x);
            }
            else {
                tails[left] = x;
            }
        }
        return tails.size();
    }
};