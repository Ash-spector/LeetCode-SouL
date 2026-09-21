class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> next(k, 0);
            next[num % k]++; //start a new subarray with the nums [i]
            for (int r = 0; r < k; r++) { //extend only the previous subarray ...

                if (dp[r] > 0) {
                    int newRemainder = (r * (num % k)) % k;

                    next[newRemainder] += dp[r];
                }
            }
            dp = next;
            for (int r = 0; r < k; r++) {
                result[r] += dp[r];
            }
        }
        return result;
    }
};