class Solution {
public:
    int calcMax(vector<int>& piles) {
        int maxi = piles[0];
        for (int i = 1; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long calcSpeed(vector<int>& piles, int mid) {
        long long totalSpeed = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalSpeed += (piles[i] + mid - 1) / mid;
        }
        return totalSpeed;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans;
        int low = 1;
        int high = calcMax(piles);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalSpeed = calcSpeed(piles, mid);

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