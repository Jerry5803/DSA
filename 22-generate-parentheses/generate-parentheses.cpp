class Solution {
public:
    void generateParenthesisHelper(int open, int close, string s, vector<string>& ans) {
        if (open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }

        if (open > 0) {
            generateParenthesisHelper(open - 1, close, s + '(', ans);
        }

        if (open < close) {
            generateParenthesisHelper(open, close - 1, s + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateParenthesisHelper(n, n, "", ans);
        return ans;
    }
};