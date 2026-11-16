
class Solution {
public:
    int recursion(int left, int right, vector<int>& nums, int target) {
        if (left > right) {
            return -1;
        }

        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            return recursion(mid + 1, right, nums, target);
        }
        else {
            return recursion(left, mid - 1, nums, target);
        }
    }

    int search(vector<int>& nums, int target) {
        return recursion(0, nums.size() - 1, nums, target);
    }
};
