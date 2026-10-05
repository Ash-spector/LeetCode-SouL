class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int a=1 ; a< nums.size(); a++){
            if(nums[i] !=nums[a]){
                i++;
                nums[i] = nums[a];
            }
        }
        return i+1;
    }
};