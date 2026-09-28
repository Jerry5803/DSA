class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProd = nums[0];
        int maxProd = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            int newMax = max({x, x * minProd, x * maxProd});
            int newMin = min({x, x * minProd, x * maxProd});

            minProd = newMin;
            maxProd = newMax;

            ans = max(ans, maxProd);
        }
        return ans;
    }
};