class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        int leftSum = 0;
        for (int num : nums) {
            total += num;
        }
        for (int i = 0; i < nums.size(); i++) {
            // Sum on the right side
            int rightSum = total - leftSum - nums[i];
            // Check pivot
            if (leftSum == rightSum) {
                return i;
            }
            // Add current element to left sum
            leftSum += nums[i];
        }
        return -1;
    }
};