class Solution {
public:
    int findMax(vector<int>& piles) {
        int maxi = piles[0];
        for (int i = 1; i < piles.size(); i++) {
            if (piles[i] > maxi) {
                maxi = piles[i];
            }
        }
        return maxi;
    }

    long long findSpeed(vector<int>& piles, int hourly) {
        long long totalSpeed = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalSpeed += (piles[i] + hourly - 1) / hourly;
        }
        return totalSpeed;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        int ans;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalSpeed = findSpeed(piles, mid);

            if (totalSpeed <= h) {
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