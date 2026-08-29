class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int zcount = 0;
        int maxlen = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] == 0) {
                zcount++;
            }

            while (zcount > 1) {
                if (nums[left] == 0) {
                    zcount--;
                }
                left++;
            }

            maxlen = max(maxlen, right - left);
        }

        return maxlen;
    }
};