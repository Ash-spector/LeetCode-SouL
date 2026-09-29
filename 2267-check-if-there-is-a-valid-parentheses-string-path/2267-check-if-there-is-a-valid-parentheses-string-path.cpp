class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if ((m + n - 1) % 2 == 1) // Path length must be even
            return false;

        vector<vector<vector<bool>>> dp(   // dp[i][j][balance]
            m,
            vector<vector<bool>>(n, vector<bool>(m + n, false))
        );

        if (grid[0][0] == ')') // Starting cell must be '('
            return false;

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                for (int balance = 0; balance <= m + n; balance++) {

                    if (!dp[i][j][balance])
                        continue;
                    if (i + 1 < m) {  // Move down
                        int newBalance = balance;

                        if (grid[i + 1][j] == '(')
                            newBalance++;
                        else
                            newBalance--;

                        if (newBalance >= 0) {
                            dp[i + 1][j][newBalance] = true;
                        }
                    }
                    if (j + 1 < n) {  // Move right
                        int newBalance = balance;

                        if (grid[i][j + 1] == '(')
                            newBalance++;
                        else
                            newBalance--;

                        if (newBalance >= 0) {
                            dp[i][j + 1][newBalance] = true;
                        }
                    }
                }
            }
        }
        return dp[m - 1][n - 1][0];
    }
};