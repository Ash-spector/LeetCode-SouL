//donot reach the graph so i have to do this with ai help 
class Solution {
public:
    struct State {
        long long score = 0;
        vector<int> indices;
    };

    State better(State a, State b) {
        if (a.score != b.score) {
            return a.score > b.score ? a : b;
        }

        return lexicographical_compare(
            a.indices.begin(), a.indices.end(),
            b.indices.begin(), b.indices.end()
        ) ? a : b;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Store: {left, right, weight, original index}
        vector<array<int, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by starting position
        sort(a.begin(), a.end());

        // Find first interval whose left > current right
        vector<int> next(n);

        for (int i = 0; i < n; i++) {
            int r = a[i][1];

            int lo = i + 1;
            int hi = n;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid][0] > r) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }

            next[i] = lo;
        }

        // dp[i][cnt] = best answer starting from i
        // when cnt intervals have already been selected
        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = n - 1; i >= 0; i--) {

            for (int cnt = 0; cnt <= 4; cnt++) {

                // Option 1: Skip current interval
                State skip = dp[i + 1][cnt];

                State best = skip;

                // Option 2: Take current interval
                if (cnt < 4) {

                    State take = dp[next[i]][cnt + 1];

                    take.score += a[i][2];
                    take.indices.push_back(a[i][3]);

                    sort(take.indices.begin(), take.indices.end());

                    best = better(best, take);
                }

                dp[i][cnt] = best;
            }
        }

        return dp[0][0].indices;
    }
};