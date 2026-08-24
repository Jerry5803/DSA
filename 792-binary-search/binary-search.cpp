class Solution {
public:
    int recursion(vector<int>& nums, int left, int right, int target) {
        if (left > right) {
            return -1;
        }
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] > target) {
            return recursion(nums, left, mid - 1, target);
        }
        else {
            return recursion(nums, mid + 1, right, target);
        }
    }

    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        return recursion(nums, left, right, target);
    }
};