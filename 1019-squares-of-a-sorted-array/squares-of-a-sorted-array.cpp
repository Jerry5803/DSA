class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        int left = 0, right = n - 1;
        int i = n - 1;
        vector<int> ans(n);

        while (left <= right) {
            if (abs(nums[left]) < abs(nums[right])) {
                ans[i] = nums[right] * nums[right];
                right--;
            }
            else {
                ans[i] = nums[left] * nums[left];
                left++;
            }
            i--;
        }
        return ans;
    }
};