class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0; 
        int high = height.size() - 1;
        int maxArea = INT_MIN;

        while (low < high) {
            int area = (high - low) * min(height[low], height[high]);
            maxArea = max(area, maxArea);

            if (height[low] < height[high]) {
                low++;
            }
            else {
                high--;
            }
        }
        return maxArea;
    }
};