class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int d[101]={0};int n=nums.size();
        for(int i=0;i<n;i++){
            d[nums[i]]++;
            if(d[nums[i]]>2)return false;
        }
        return true;}
};