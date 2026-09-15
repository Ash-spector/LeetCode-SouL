class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        // palindrome[i][j] = true if s[i...j] is a palindrome
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) { // Build palindrome table
            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 1 || palindrome[i + 1][j - 1])) {

                    palindrome[i][j] = true;
                }
            }
        }
        // dp[i] = maximum palindromes we can get
        // from index i to the end
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];  // : skip current character

            // Option 2: take a palindrome starting at i
            for (int j = i + k - 1; j < n; j++) {

                if (palindrome[i][j]) {
                    dp[i] = max(dp[i], 1 + dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
};