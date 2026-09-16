class Solution {
public:
    int findMax(vector<int>& piles) {
        int maxi = piles[0];
        for (int i = 1; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long findTime(vector<int>& piles, int hourly) {
        long long totalTime = 0;

        for (int i = 0; i < piles.size(); i++) {
            totalTime += ((piles[i] + hourly -1) / hourly);
        }
        return totalTime;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        int ans;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long totalTime = findTime(piles, mid);

            if (totalTime <= h) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};