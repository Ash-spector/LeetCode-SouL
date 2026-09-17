class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        const int INF = 1e9;
        vector<int> best(n, INF);// best[i] = minimum length of a valid subarray completely inside arr[0 ... i]

        int ans = INF;
        int left = 0;
        int sum = 0;
        int minLen = INF;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // If current subarray has target sum
            if (sum == target) {
                int len = right - left + 1;

                // Need another subarray before 'left'
                if (left > 0 && best[left - 1] != INF) {
                    ans = min(ans, len + best[left - 1]);
                }

                minLen = min(minLen, len);
            }
            // Carry the best subarray seen so far
            if (right == 0) {
                best[right] = minLen;
            } else {
                best[right] = min(best[right - 1], minLen);
            }
        }

        return ans == INF ? -1 : ans;
    }
};