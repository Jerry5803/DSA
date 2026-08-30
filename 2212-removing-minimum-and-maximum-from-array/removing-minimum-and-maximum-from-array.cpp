class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[maxIdx]) {
                maxIdx = i;
            }
            if (nums[i] < nums[minIdx]) {
                minIdx = i;
            }
        }

        if (minIdx > maxIdx) {
            swap(minIdx, maxIdx);
        }

        int removeFromLeft = maxIdx + 1;
        int removeFromRight = n - minIdx;
        int removeFromBoth = (minIdx + 1) + (n - maxIdx);

        return min({removeFromLeft, removeFromRight, removeFromBoth});
    }
};