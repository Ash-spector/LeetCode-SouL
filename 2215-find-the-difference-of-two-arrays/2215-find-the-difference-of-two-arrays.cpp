class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1 (nums1.begin(), nums1.end());
        set<int> s2 (nums2.begin(),nums2.end());
    vector<int> a1;
    vector<int>a2;
    for(int i : s1){
        if(s2.find(i) == s2.end()){
            a1.push_back(i);
        }
    }
    for(int i: s2){
        if(s1.find(i) ==s1.end()){
            a2.push_back(i);
        }
    }
    return{a1,a2};
    }
};