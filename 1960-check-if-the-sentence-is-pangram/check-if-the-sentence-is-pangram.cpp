class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> freq(26, false);

        for (char ch : sentence) {
            freq[ch - 'a'] = true;
        }

        for (auto it : freq) {
            if (!it) {
                return false;
            }
        }
        return true;
    }
};